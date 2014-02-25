#!/usr/bin/perl

use strict;
use warnings;

use FindBin;

my @macro = qw(
	YAK_%s_%s_INCLUDED
	YAK_USE_%s_%s
	YAK_USING_%s_%s
);

sub process_ipp
{
	my $lib = shift;
	open my $fh, '>', "$FindBin::Bin/test_config_$lib.ipp";
	print $fh <<EOF;
// Automatically generated file, do not edit!
#include "config.hpp"
#include <boost/type_traits/is_same.hpp>

EOF
	foreach my $tmpl (@macro) {
		foreach my $from (qw(BOOST STD)) {
			my $uname = sprintf $tmpl, $from, uc($lib);
			my $lname = lc($uname);
			print $fh <<EOF
const int $lname =
#if defined($uname)
1
#else
0
#endif
;
EOF
		}
	}
	close $fh;
}

my %suffix = (
	fb => '_force_boost_%s',
	fs => '_force_std_%s',
	bi => '_boost_%s_included',
	si => '_std_%s_included',
	bsi => '_both_%s_included',
);

sub process_cpp
{
	my ($lib, $binc, $sinc, $mays, @types) = @_;
	my $libu = uc($lib);
	foreach my $force ('', 'fb', 'fs') {
		foreach my $inc ('', 'bi', 'si', 'bsi') {
			my $suffix = (($force eq '' && $inc eq '') ?  '' : "_$force$inc");
			my $test = '';
			$test .= sprintf($suffix{$force}, $lib) if exists $suffix{$force};
			$test .= sprintf($suffix{$inc}, $lib) if exists $suffix{$inc};
			$test = "_$lib" if $test eq '';
			my $use = 
				$force eq 'fb' ? 'boost' :
				$force eq 'fs' ? 'std' :
				$inc eq 'bi' ? 'boost' :
				$inc eq 'si' ? 'std' : '';
			my $incb = $use eq 'boost' || $inc eq 'bi' || $inc eq 'bsi';
			my $incs = $use eq 'std' || $inc eq 'si' || $inc eq 'bsi';
			open my $fh, '>', "$FindBin::Bin/test_config_$lib$suffix.cpp";
			print $fh <<EOF;
// Automatically generated file, do not edit!
EOF
			print $fh <<EOF if $inc eq 'si' || $inc eq 'bsi' || $force eq 'fs';
#if __cplusplus >= 201103L
EOF
			print $fh <<EOF;
#include <boost/test/auto_unit_test.hpp>

#define YAK_${libu}_REQUIRED
EOF
			print $fh "#include <$binc>\n" if $inc eq 'bi' || $inc eq 'bsi';
			print $fh "#include <$sinc>\n" if $inc eq 'si' || $inc eq 'bsi';
			print $fh "#define YAK_FORCE_BOOST_$libu\n" if $force eq 'fb';
			print $fh "#define YAK_FORCE_STD_$libu\n" if $force eq 'fs';
			print $fh <<EOF;
#include "test_config_$lib.ipp"

EOF
			print $fh <<EOF if $inc eq '' && $force eq '';
#include <$binc>
#if __cplusplus >= 201103L
#include <$sinc>
#endif

EOF
			print $fh <<EOF;
BOOST_AUTO_TEST_CASE(config$test)
{
EOF
			my $type = @types ? $lib.'<'.join(',', @types).'>' : $lib;
			if($use eq 'boost') {
				print $fh "\tBOOST_CHECK((boost::is_same<yak::std11::$type, boost::$type >::value));\n";
				printf $fh "\tBOOST_CHECK(%syak_boost_${lib}_included);\n", ($incb ? ' ' : '!');
				if($mays) {
					printf $fh "#if __cplusplus < 201103L\n\tBOOST_CHECK(%syak_std_${lib}_included);\n#endif\n", ($incs ? ' ' : '!');
				} else {
					printf $fh "\tBOOST_CHECK(%syak_std_${lib}_included);\n", ($incs ? ' ' : '!');
				}
				print $fh <<EOF;
	BOOST_CHECK( yak_use_boost_$lib);
	BOOST_CHECK(!yak_use_std_$lib);
EOF
			} elsif($use eq 'std') {
				print $fh "\tBOOST_CHECK((boost::is_same<yak::std11::$type, std::$type >::value));\n";
				printf $fh "\tBOOST_CHECK(%syak_boost_${lib}_included);\n", ($incb ? ' ' : '!');
				if($mays) {
					printf $fh "#if __cplusplus < 201103L\n\tBOOST_CHECK(%syak_std_${lib}_included);\n#endif\n", ($incs ? ' ' : '!');
				} else {
					printf $fh "\tBOOST_CHECK(%syak_std_${lib}_included);\n", ($incs ? ' ' : '!');
				}
				print $fh <<EOF;
	BOOST_CHECK(!yak_use_boost_$lib);
	BOOST_CHECK( yak_use_std_$lib);
EOF
			} elsif($inc eq 'bsi') {
				print $fh <<EOF;
	BOOST_CHECK(
		(boost::is_same<yak::std11::$type, boost::$type >::value && yak_use_boost_$lib && !yak_use_std_$lib) ||
		(boost::is_same<yak::std11::$type, std::$type >::value && yak_use_std_$lib && !yak_use_boost_$lib)
	);
	BOOST_CHECK(yak_boost_${lib}_included);
	BOOST_CHECK(yak_std_${lib}_included);
EOF
			} else { # $force eq '' && $inc eq ''
				print $fh <<EOF;
#if __cplusplus >= 201103L
	BOOST_CHECK(
EOF
				if($mays) {
					print $fh <<EOF;
		(boost::is_same<yak::std11::$type, boost::$type >::value && yak_boost_${lib}_included && yak_use_boost_$lib && /* !yak_std_${lib}_included && */ !yak_use_std_$lib) ||
EOF
				} else {
					print $fh <<EOF;
		(boost::is_same<yak::std11::$type, boost::$type >::value && yak_boost_${lib}_included && yak_use_boost_$lib && !yak_std_${lib}_included && !yak_use_std_$lib) ||
EOF
				}
				print $fh <<EOF;
		(boost::is_same<yak::std11::$type, std::$type >::value && yak_std_${lib}_included && yak_use_std_$lib && !yak_boost_${lib}_included && !yak_use_boost_$lib)
	);
#else // __cplusplus >= 201103L
	BOOST_CHECK(
		(boost::is_same<yak::std11::$type, boost::$type >::value && yak_boost_${lib}_included && yak_use_boost_$lib && !yak_std_${lib}_included && !yak_use_std_$lib)
	);
#endif // __cplusplus >= 201103L
EOF
			}
			print $fh <<EOF;
	BOOST_CHECK(!yak_using_boost_$lib);
	BOOST_CHECK(!yak_using_std_$lib);
}
EOF
			print $fh <<EOF if $inc eq 'si' || $inc eq 'bsi' || $force eq 'fs';
#endif // __cplusplus >= 201103L
EOF

			close $fh;
		}
	}
}

foreach my $spec (@ARGV) {
	my ($lib, $binc, $sinc, $mays, @types) = split /,/, $spec;
	$lib = lc $lib;
	process_ipp($lib);
	process_cpp($lib, $binc, $sinc, $mays, @types);
}
__END__

=pod

=head1 NAME

gen_test_config.pl - Generate config tests automatically

=head1 SYNOPSIS

perl gen_test_config.pl C<specs>...

	perl test/gen_test_config.pl regex,boost/regex.hpp,regex,0 tuple,boost/tuple/tuple.hpp,tuple,1,int

=head1 DESCRIPTION

C<specs> consists of comma separated values:

=over 4

=item *

A library name

=item *

A header name for boost

=item *

A header name for std

=item *

A flag that Boost.Test may include std header in C++11 mode

=item *

Identifiers/keywords to constitute a type to be checked.
If there is no item, just a library name is checked as a type.
If there are items, library_nameE<lt>itemsE<gt> is checked as a type.

=back

=cut
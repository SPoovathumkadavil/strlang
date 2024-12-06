%
%   Output File
%

.file slib_out

.use color .from slib_defs

.chapter output
.begin stage print \
   	: cr(.bool)::false \
	  color(.oneof .AnsiColor)::white \
	  text(.string)
	.out : text->.format : text->"{1}[{2}m{3}[{4}m" \
				          f1->.AnsiEscape \
				          f2->.local::color \
				    	    f3->.local::text \
				    	    f4->.AnsiColor::reset
	.begin stage should_carriage_return
		.out : text->"\n"
	.end should_carriage_return
	.compare : a->.local::cr b->.true
	.branch : equal->.true to->.should_carriage_return
.end print

.begin stage typewrite \
	: cr(.bool)::false \
	  color(.string) \
	  speed(.integer) \
	  text(.string)
	.define n .int 0
	.begin stage t_loop
		.sleep : time->0.03
		.out : text->(.iterable .local::text)::.n
		.increment .n 1
		.branch : equal->(.length .local::text) to->.t_loop
	.end t_loop
	.print : cr->.local::cr text->""
.end typewrite

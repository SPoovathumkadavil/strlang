%
%   Definition Files
%

.file slib_defs

.begin chapter colors
.define AnsiColor .map <id int> [ reset => 0 \
						          white => 37 \
 					     		  red => 31 \
						 		  blue => 94 \
						 		  purple => 95 \
								  cyan => 96 \
						 		  dark_cyan => 36 \
						 		  yellow => 93 \
						 		  green => 92 ]
.define AnsiEscape .string "\033"
.end colors

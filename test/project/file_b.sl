%
%   Auxillery File
%

.file file_b

.define c [ red; blue; green; ]
.begin stage other : col(.oneof c)

    .typewrite cr color->col speed->2 ? "We are at other now."  % print typewrite with \n, color, speed set
    .back                                                       % return to stage

.end other

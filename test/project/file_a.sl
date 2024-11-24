%
%   Main Project File
%

.file file_a
.import file_b

.entry main                   % project entry-point definition
.begin stage main             % main stage

    .typewrite cr ? "Hello!"  % print with "carriage return" or \n
    .do_thing                 % from file_b
    .other                    % switch to other stage defined in file_b
    .back                     % final return

.end main

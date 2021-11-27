%%
%Run this before any analysis. After running, variable "measurements" is
%available

%%
%load file to string variable

% Do cd path_to_repo\Matlab in the command window to set correct working directory
fileName = '../Data/Andmed2.json';
stringData = fileread(fileName);

%%
%create a struct
measurements = jsondecode(stringData);

%%
%convert SQL date string to datetime object
for i=1:length(measurements)
    measurements(i).date = datetime(measurements(i).date,'InputFormat','yyyy-MM-dd HH:mm:ss');
end

%%
%Set up initial condition struct
t_i = duration (2, 0, 0);
t_s = duration (0, 0, 2);
ic_n = ceil(t_i/t_s) - 1;

initial_h = measurements(1).humidity;
initial_t = measurements(1).temperature;
i_h = ones(1,ic_n) * initial_h;
i_t = ones(1, ic_n) * measurements(1).temperature;
sample_offset = [];

for i=1:ic_n
    sample_period = seconds(t_s);
    sample_offset(1, i) = sample_period * i;
end
i_d = duration(0, 0, sample_offset);
i_id = zeros(1, ic_n);

ic = struct('id', i_id, 'humidity', i_h, 'temperature', i_t, 'time', i_d);





%%
%translate to relative time
tr = struct('time', []);
for i=1:length(measurements)
    tr(i).time = t_i + measurements(i).date - measurements(1).date;
end

%%
%prepend initial conditions




%%
%split structs
h1 = struct('date', num2cell([ic.time [tr.time]]), 'humidity', num2cell( [ic.humidity [measurements.humidity]]   ));
%h2 = struct('date', {measurements.date}, 'humidity', { measurements.humidity2});

t1 = struct('date', num2cell([ic.time [tr.time]]), 'temperature', num2cell( [ic.temperature [measurements.temperature]] ));
%t2 = struct('date', {measurements.date}, 'temperature', { measurements.temperature2});

%%
%create timetable object for analysis
T_h1 = struct2table(h1);
TT_h1 = table2timetable(T_h1, 'RowTimes', 'date');

T_t1 = struct2table(t1);
TT_t1 = table2timetable(T_t1, 'RowTimes', 'date');

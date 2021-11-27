%%
%plot
p_humidity1 = [measurements.humidity1];
p_temperature1 = [measurements.temperature1];
p_humidity2 = [measurements.humidity2];
p_temperature2 = [measurements.temperature2];

p_date = [measurements.date];

figure;
subplot(2, 1, 1);
xlabel('Time')
hold on;
%yyaxis right;
ylabel('Relative humidity (%)')
plot(p_date, p_humidity1, 'Color', [0.9 0.1 0], 'LineStyle', '-');
plot(p_date, p_humidity2.*0.5629 + 31.1248, 'Color', [0 0.1 0.9], 'LineStyle', '-');
legend("near sensor", "far sensor");
% yyaxis right;
hold off;

subplot(2, 1, 2);
% ylabel('Temperature (C)')
hold on;
plot(p_date, p_temperature1, 'Color', [0.65 0.1 0], 'LineStyle', '-');
plot(p_date, p_temperature2, 'Color', [0 0.1 0.65], 'LineStyle', '-');

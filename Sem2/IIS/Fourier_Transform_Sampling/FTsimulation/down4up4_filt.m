% This function downsample a sound file by a factor of 4 and then
% interpolate it back to the original sampling rate. 
% A length 31 FIR lowpass filter is applied for down-sampling
% Interpolation is done by using a length 33 FIR interpolation filter .
% The program plays the sound file to allow perceptual evaluatio of sound quality.
% It also displays the waveforms and spectrums of original, down-sampled, and upsampled signal
% The filter response is also displayed
% Yao Wang, Polytechnic University, 1/11/2004

function[]=down4up4_filt(InFilename,OutFilename);

% Usage : down4up4_nofilt('Infilename','Outfilename')

fprintf('\n Read in the original sound \n')
[y,fs]=wavread(InFilename);

%first shorten the sequence so that the length is multiple of 4
orig_length=length(y);
N=floor(orig_length/4)*4;
y = y(1:N);
disp([fs,N]);

% Play it
sound(y,fs);
figure(1);
subplot(1,2,1),bar(y(2000:2060),0.02);axis tight;title('Waveform of Original');
subplot(1,2,2),psd(y,256,fs);axis([0,fs/2,-60,0]);ylabel('');xlabel('');title('Spectrum of Original');

fprintf('\n Hit a key to continue\n');
pause

% Downsample with a default length 31 FIR prefilter:
fprintf('\n The downsampled sound \n')
x=decimate(y,4,30,'FIR');
sound(x,fs/4);
figure(2);
subplot(1,2,1),bar(x(2000/4:2060/4),0.02);axis tight;title('Waveform of Down4');
subplot(1,2,2),psd(x,256,fs/4);axis([0,fs/2,-60,0]);ylabel('');xlabel('');title('Spectrum of Down4');

fprintf('\n Hit a key to continue\n');
pause;

%display the prefilter used
figure(3);
hdec=fir1(30,1/4);[hdecspec,f]=freqz(hdec,1);

subplot(1,2,1),bar(-15:1:15,hdec,0.02);axis tight;title('Prefilter Impulse Response ');
subplot(1,2,2),
plot(f/pi,20*log10(abs(hdecspec)));axis tight;title('Prefilter Frequency Response');ylabel('');xlabel('');


fprintf('\n Hit a key to continue\n');
pause;


%Interpolation using a default FIR interpolation filter
fprintf('\n The interpolated sound \n')
[z,hintp]=interp(x,4);
%interp uses a default filter, which is returned in hintp

sound(z,fs);
figure(4);
subplot(1,2,1),bar(z(2000:2060),0.02);axis tight;title('Waveform of Up4');
subplot(1,2,2),psd(z,256,fs);axis([0,fs/2,-60,0]);ylabel('');xlabel('');title('Spectrum of Up4');

fprintf('\n Hit a key to continue\n');
pause;


%display the prefilter used
figure(5);
[hintpspec,f]=freqz(hintp,1);

subplot(1,2,1),bar(-16:1:16,hintp,0.02);axis tight;title('Intp Filter Impulse Response ');
subplot(1,2,2),
plot(f/pi,20*log10(abs(hintpspec)));axis tight;title('Intp Filter Frequency Response');ylabel('');xlabel('');



fprintf('\n Hit a key to continue\n');
pause;
% Save the interpolated sequence
wavwrite(z,fs,OutFilename);

% Calculate the MSE
D=y-z;
MSE=mean(D.^2);
fprintf('\n Error between original and interpolated = %g\n\n',MSE )



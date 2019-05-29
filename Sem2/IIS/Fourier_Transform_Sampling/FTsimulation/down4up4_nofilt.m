% This function downsample a sound file by a factor of 4 and then
% interpolate it back to the original sampling rate. 
% No prefilter is applied for down-sampling
% Interpolation is down by repeating every sample 4 times
% The program plays the sound file to allow perceptual evaluatio of sound quality.
% It also displays the waveforms and spectrums of original, down-sampled, and upsampled signal
% Yao Wang, Polytechnic University, 1/11/2004

function[]=down4up4_nofilt(InFilename,OutFilename);

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

% Downsample without prefiltering: take every 4th sample
fprintf('\n The downsampled sound \n')
x=y(1:4:N);
sound(x,fs/4);
figure(2);
subplot(1,2,1),bar(x(2000/4:2060/4),0.02);axis tight;title('Waveform of Down4');
subplot(1,2,2),psd(x,256,fs/4);axis([0,fs/2,-60,0]);ylabel('');xlabel('');title('Spectrum of Down4');

fprintf('\n Hit a key to continue\n');
pause;


%Interpolation by repeating each sample 4 times
fprintf('\n The interpolated sound \n')
z=zeros(N,1);
%interpolate by first copy the  samples in x to every 4th sample to z starting from 1st sample
% then starting at 2nd sample, and so on
z(1:4:N)=x;
z(2:4:N)=x;
z(3:4:N)=x;
z(4:4:N)=x;
%interp(x,4);

sound(z,fs);
figure(3);
subplot(1,2,1),bar(z(2000:2060),0.02);axis tight;title('Waveform of Up4');
subplot(1,2,2),psd(z,256,fs);axis([0,fs/2,-60,0]);ylabel('');xlabel('');title('Spectrum of Up4');

fprintf('\n Hit a key to continue\n');
pause;
% Save the interpolated sequence
wavwrite(z,fs,OutFilename);

% Calculate the MSE
D=y-z;
MSE=mean(D.^2);
fprintf('\n Error between original and interpolated = %g\n\n',MSE )



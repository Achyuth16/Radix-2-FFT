//task4

#include <stdio.h>
#include <stdlib.h>
int main()

{
	
int i;
y[1].real = in[0].real - in[1].real;
y[1].imaginary = in[0].imaginary - in[1].imaginary;
return y;
}
//Breaking the input for recursion
for (i=0;i<N;i++)
{
if(i%2==0)
{//even indexes
xev[i/2].real = in[i].real;
xev[i/2].imaginary = in[i].imaginary;
}
else{//odd indexes
xod[(i-1)/2].real        = in[i].real;
xod[(i-1)/2].imaginary    = in[i].imaginary;
}
}
//recursive calls
a = fft(xev,N/2);
b = fft(xod,N/2);

for (i=0;i<N;i++)
{
y[i].real=a[i%(N/2)].real + b[i%(N/2)].real*cos(2*3.14*i/N)+Xh[i%(N/2)].imaginary*sin(2*3.14*i/N);
y[i].imaginary=a[i%(N/2)].imaginary+Xh[i%(N/2)].imaginary*cos(2*3.14*i/N)-b[i%(N/2)].real*sin(2*3.14*i/N);
}
//deallocating the waste memory
free(a);
free(b);
return y;//returning the result
}
//the main function
int main(int argc,char *argv[])
{
int N,i;
complex *x;//input
complex *y;//variable to store FFT of the input

//asking for the no of points in the FFT
printf("\n enter N must be a power of 2:");
scanf("%d",&N);
//allocating memory for the input
x = (complex*)malloc(N*sizeof(complex));
//taking the input
for(i=0;i<N;i++){
printf("\nenter %dth element real then imaginary",i);
scanf("%f",&(x[i].real));  
scanf("%f",&(x[i].imaginary));
}
//calling the fft function
y= fft(x,N);
//displaying the result
printf("\n FFT of the input is as follows");
for(i=0;i<N;i++)
{
printf("\n c[%d] = %.2f + j %.2f",i,y[i].real,y[i].imaginary);
}
return 0;

}

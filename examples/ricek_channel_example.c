//
// Fading generator example
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>
#include <getopt.h>

#include "liquid.experimental.h"

#define OUTPUT_FILENAME "ricek_channel_example.m"

// print usage/help message
void usage()
{
    printf("modem_example [options]\n");
    printf("  h     : print help\n");
    printf("  n     : number of samples\n");
    printf("  f     : maximum doppler frequency (0,0.5)\n");
    printf("  K     : Rice K factor, linear, greater than zero\n");
    printf("  O     : mean power, linear(Rice-K distribution 'omega')\n");
}

int main(int argc, char*argv[])
{
    // options
    unsigned int h_len=51;  // doppler filter length
    float fd=0.1f;          // maximum doppler frequency
    float K=2.0f;           // Rice fading factor
    float omega=1.0f;       // mean power
    float theta=0.0f;       // angle of arrival
    unsigned int n=100;     // number of samples

    int dopt;
    while ((dopt = getopt(argc,argv,"hn:f:K:O:")) != EOF) {
        switch (dopt) {
        case 'h':   usage();               return 0;
        case 'n':   n     = atoi(optarg);  break;
        case 'f':   fd    = atof(optarg);  break;
        case 'K':   K     = atof(optarg);  break;
        case 'O':   omega = atof(optarg);  break;
        default:
            exit(1);
        }
    }

    // generate objects
    ricek_channel q = ricek_channel_create(h_len, K, fd, theta);

    FILE*fid = fopen(OUTPUT_FILENAME,"w");
    fprintf(fid,"%% %s, auto-generated file\n\n",OUTPUT_FILENAME);
    fprintf(fid,"clear all;\nclose all;\n\n");

    // generate complex fading envelope
    float complex x=omega, y;

    unsigned int i;
    for (i=0; i<n; i++) {
        ricek_channel_execute(q,x,&y);

        printf("y(%4u) = %12.8fe + j*%12.8f;\n",i+1,crealf(y),cimagf(y));
        fprintf(fid, "y(%4u) = %12.5e + j*%12.5e;\n",i+1,crealf(y),cimagf(y));
    }

    fprintf(fid,"\n\n");
    fprintf(fid,"t=0:length(y)-1;\n");
    fprintf(fid,"R=20*log10(abs(y));\n");
    fprintf(fid,"figure;\n");
    fprintf(fid,"plot(t,R,'-','LineWidth',2);\n");
    fprintf(fid,"xlabel('time [samples]');\n");
    fprintf(fid,"ylabel('fading amplitude [dB]');\n");
    fprintf(fid,"grid on;\n");

    fclose(fid);

    printf("results written to %s\n", OUTPUT_FILENAME);

    // clean up objects
    ricek_channel_destroy(q);

    printf("done.\n");
    return 0;
}


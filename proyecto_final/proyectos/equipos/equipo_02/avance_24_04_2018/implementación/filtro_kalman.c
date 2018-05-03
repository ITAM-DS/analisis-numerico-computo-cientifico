/** A simple kalman filter example by Adrian Boeing 
 www.adrianboeing.com 
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double frand() {
    return 2*((rand()/(double)RAND_MAX) - 0.5);
}

int main() {

    //initial values for the kalman filter
    float x_est_last = 0;
    float P_last = 0;
    //the noise in the system
    float Q = 0.022;
    float R = 0.617;
    
    float K;
    float P;
    float P_temp;
    float x_temp_est;
    float x_est;
    float z_measured; //the 'noisy' value we measured
    float z_real = 0.5; //the ideal value we wish to measure
    
    srand(0);
    
    //initialize with a measurement
    x_est_last = z_real + frand()*0.09;
    
    float sum_error_kalman = 0;
    float sum_error_measure = 0;
    
    for (int i=0;i<30;i++) {
        //do a prediction
        x_temp_est = x_est_last;
        P_temp = P_last + Q;
        //calculate the Kalman gain
        K = P_temp * (1.0/(P_temp + R));
        //measure
        z_measured = z_real + frand()*0.09; //the real measurement plus noise
        //correct
        x_est = x_temp_est + K * (z_measured - x_temp_est); 
        P = (1- K) * P_temp;
        //we have our new system
        
        printf("Ideal    position: %6.3f \n",z_real);
        printf("Mesaured position: %6.3f [diff:%.3f]\n",z_measured,fabs(z_real-z_measured));
        printf("Kalman   position: %6.3f [diff:%.3f]\n",x_est,fabs(z_real - x_est));
        
        sum_error_kalman += fabs(z_real - x_est);
        sum_error_measure += fabs(z_real-z_measured);
        
        //update our last's
        P_last = P;
        x_est_last = x_est;
    }
    
    printf("Total error if using raw measured:  %f\n",sum_error_measure);
    printf("Total error if using kalman filter: %f\n",sum_error_kalman);
    printf("Reduction in error: %d%% \n",100-(int)((sum_error_kalman/sum_error_measure)*100));
    
    
    return 0;
}
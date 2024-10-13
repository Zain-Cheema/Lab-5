#include <stdio.h>

#define NUM_MONTHS 12

void Monthly_Sales(double sale[]);   //Functions and storing floating point values.
void Sales_Summary(double sale[]);
void Moving_Average(double sale[]);
void Sales_highlow(double sale[]);

int main() {
    double sale[NUM_MONTHS];
    
    printf("Enter sales for each month:\n");    //Data for each month.
    for (int i = 0; i < NUM_MONTHS; i++) {
        printf("Month %d: ", i + 1);
        scanf("%lf", &sale[i]);
    }
    
    Monthly_Sales(sale);
    Sales_Summary(sale);
    Moving_Average(sale);
    Sales_highlow(sale);
    
    return 0;
}

void Monthly_Sales(double sale[]) {
    const char* month[NUM_MONTHS] = {"January", "February", "March", "April", "May", 
                                      "June", "July", "August", "September", "October", 
                                      "November", "December"};
    printf("\nMonthly Sales Report for 2024\n");
    printf("Month\t\tSales\n");
    for (int i = 0; i < NUM_MONTHS; i++) {
        printf("%s\t%.2f\n", month[i], sale[i]);
    }
}

void Sales_Summary(double sale[]) {
    double min = sale[0], max = sale[0], sum = 0;
    int min_index = 0, max_index = 0;
    const char* month[NUM_MONTHS] = {"January", "February", "March", "April", "May", 
                                      "June", "July", "August", "September", "October", 
                                      "November", "December"};
    
    for (int i = 0; i < NUM_MONTHS; i++) {
        if (sale[i] < min) {
            min = sale[i];
            min_index = i;
        }
        if (sale[i] > max) {
            max = sale[i];
            max_index = i;
        }
        sum += sale[i];
    }
    printf("\nSales Summary Report:\n");
    printf("Minimum sales: %.2f (%s)\n", min, month[min_index]);
    printf("Maximum sales: %.2f (%s)\n", max, month[max_index]);
    printf("Average sales: %.2f\n", sum / NUM_MONTHS);
}

void Moving_Average(double sale[]) {
    printf("\nSix-Month Moving Average Report:\n");
    const char* month_name[NUM_MONTHS] = {"January", "February", "March", "April", "May", 
                                    "June", "July", "August", "September", "October", 
                                      "November", "December"};

    for (int i = 0; i <= NUM_MONTHS - 6; i++) {
        double sum = 0;
        for (int j = 0; j < 6; j++) {
            sum += sale[i + j];
        }
        printf("%s - %s: %.2f\n", month_name[i], month_name[i + 5], sum / 6);
    }
}

void Sales_highlow(double sale[]) {
    double CopySale[NUM_MONTHS];
    const char* month[NUM_MONTHS] = {"January", "February", "March", "April", "May", 
                                      "June", "July", "August", "September", "October", 
                                      "November", "December"};
    
    for (int i = 0; i < NUM_MONTHS; i++) {    //Creating copy of sales for sorting.
        CopySale[i] = sale[i];
    }
    
    for (int i = 0; i < NUM_MONTHS - 1; i++) {     //Simple selection sort.
        for (int j = i + 1; j < NUM_MONTHS; j++) {
            if (CopySale[i] < CopySale[j]) {
                double temp = CopySale[i];
                CopySale[i] = CopySale[j];
                CopySale[j] = temp;
                
                const char* temp = month[i];
                month[i] = month[j];
                month[j] = temp;
            }
        }
    }
    
    printf("\nSales Report (highest to lowest) :\n");
    printf("Month\t\tSales\n");
    for (int i = 0; i < NUM_MONTHS; i++) {
        printf("%s\t%.2f\n", month[i], CopySale[i]);
    }
}

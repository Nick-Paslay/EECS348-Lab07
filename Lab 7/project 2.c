#include "stdio.h"
float kelvin_to_C(float temp) { // function to turn kelvin into celcius
    return temp - 273.15;
}

float f_to_C(float temp) { // function to turn farenheit into celcius 
    return (temp- 32) * 5.0 / 9.0;
}

const char* temperature_category(float temp) { // our if else block that takes the celcius temperature and determines what will be returned
    if (temp < 0) {
        return "Freezing cold";
    } else if (temp < 10) {
        return "Too cold";
    } else if (temp < 25) {
        return "Comfortable";
    } else if (temp < 35) {
        return "Hot";
    } else {
        return "Extremely hot";
    }
}

int main(){
    float temp, celcius; // creates variables
    char unit;
    printf("Enter temperature and unit (K, C, or F): "); // asks for unit and temp. ex: 300 F
    scanf("%f %c", &temp, &unit);

    if (unit == 'K'){ // runs each if else statement to find the correct unit the user is using. swaps it to celcius.
        celcius = kelvin_to_C(temp);
    }
    else if (unit == 'F'){
        celcius = f_to_C(temp);
    }
    else if(unit == 'C'){
        celcius = temp;
    }
    else {
        printf("invalid.");
        return 1;
    }
    printf("Category: %s\n", temperature_category(celcius)); // after swapping to celcius, gives it to the temperature-category to determine what needs to be returned.

    return 0;
}

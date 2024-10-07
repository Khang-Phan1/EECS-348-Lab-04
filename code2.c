#include <stdio.h>

//conversion functions
float celsius_to_fahrenheit(float celsius) {
    return (9.0/5.0)*celsius+32;
}

float fahrenheit_to_celsius(float fahrenheit) {
    return (5.0/9.0)*(fahrenheit-32);
}

float celsius_to_kelvin(float celsius) {
    return celsius+273.15;
}

float kelvin_to_celsius(float kelvin) {
    return kelvin-273.15;
}

float fahrenheit_to_kelvin(float fahrenheit) {
    return (5.0/9.0)*(fahrenheit-32)+273.15;
}

float kelvin_to_fahrenheit(float kelvin) {
    return (9.0/5.0)*(kelvin-273.15)+32;
}

void categorize_temperature(float celsius) {
    //categorizes temperature and gives short advise accordingly, will use celsius
    if (celsius < 0) {
        if (celsius < -89.2) {
            //lowest ever recorded temperature, as such, any lower value is unlikely
            printf("Warning: Temperature is found to be extremely low, possible input error.\n");
        }
        printf("Temperature category: Freezing\n");
        printf("Weather Advisory: Stay indoors.");
    }
    else if (celsius >= 0 && celsius < 10) {
        printf("Temperature category: Cold\n");
        printf("Weather Advisory: Wear a jacket.");
    }
    else if (celsius >= 10 && celsius < 25) {
        printf("Temperature category: Comfortable\n");
        printf("Weather Advisory: You should be comfortable.");
    }
    else if (celsius >= 25 && celsius < 35) {
        printf("Temperature category: Hot\n");
        printf("Weather Advisory: Dress lightly");
    }
    else {
        if (celsius > 56.7) {
            //highest ever recorded temperature, as such, any value higher is unlikely
            printf("Warning: Temperature is found to be extremely high, possible input error.\n");
        }
        printf("Temperature category: Extreme Heat\n");
        printf("Weather Advisory: Stay in the shade");
    }
}

int main() {
    float temperature, convert;
    int current, final;
    while(1) {
        //loops in case of invalid input
        printf("Enter the temperature: ");
        scanf("%f", &temperature);
        printf("Choose the current scale (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
        scanf("%d", &current);
        printf("Convert to (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
        scanf("%d", &final);

        if (current == 1 && final == 2) {
            convert = celsius_to_fahrenheit(temperature);
            printf("Converted temperature: %0.2f°F\n", convert);
            break;
        }
        else if (current == 1 && final == 3) {
            convert = celsius_to_kelvin(temperature);
            if (convert < 0) {
                //checks for negative kelvin value
                printf("Kelvin can not be negative.\n");
                continue;
            }
            printf("Converted temperature: %0.2fK\n", convert);
            break;
        }
        else if (current == 2 && final == 1) {
            convert = fahrenheit_to_celsius(temperature);
            printf("Converted temperature: %0.2f°C\n", convert);
            break;
        }
        else if (current == 2 && final == 3) {
            convert = fahrenheit_to_kelvin(temperature);
            if (convert < 0) {
                printf("Kelvin can not be negative.\n");
                continue;
            }
            printf("Converted temperature: %0.2fK\n", convert);
            break;
        }
        else if (current == 3 && final == 1) {
            if (temperature < 0) {
                printf("Kelvin can not be negative.\n");
                continue;
            }
            convert = kelvin_to_celsius(temperature);
            printf("Converted temperature: %0.2f°C\n", convert);
            break;
        }
        else if (current == 3 && final == 2) {
            if (temperature < 0) {
                printf("Kelvin can not be negative.\n");
                continue;
            }
            convert = kelvin_to_fahrenheit(temperature);
            printf("Converted temperature: %0.2f°F\n", convert);
            break;
        }
        else {
            if (current == final) {
                //checks for conversion to same scale
                printf("Conversion to same scale, invalid.\n");
            }
            else if (current < 1 || current > 3) {
                //checks for the initial scale being out of range
                printf("Input value is out of range.\n");
            }
            else if (final < 1 || final > 3) {
                //checks for the conversion target being out of range
                printf("Conversion target is out of range.\n");
            }
        }
    }

    if (final == 1) {
        //already in celsius
        categorize_temperature(convert);
    }
    else if (final == 2) {
        //converts fahrenheit back to celsius
        categorize_temperature(fahrenheit_to_celsius(convert));
    }
    else {
        //converts kelvin back to celsius
        categorize_temperature(kelvin_to_celsius(convert));
    }
}
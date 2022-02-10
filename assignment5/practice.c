#include <stdio.h>
#include <stdlib.h>

int count_line(FILE* fp){
    char line_string[1000];
    int line = 0;
    if(fp == NULL){
        return 0;
    }
    rewind(fp);
    fgets(line_string,sizeof(line_string), fp);  // read the first line
    while(!feof(fp)){
        fgets(line_string,sizeof(line_string), fp);  // read the next line until the end of the file
        line++;
    }
    return line;
}

void display_sales(char column_headers[100][200], int* sales, int rows){
    for(int i = 1; i < 6; i++){  // for loop to print each category's sales
        int sum = 0;
        for(int j = 0; j < rows; j++){  // inner for loop to calculate the total sales of each category
            sum += sales[5 * j + i - 1];
        }
        printf("Total %s sales: %d\n", column_headers[i], sum);
    }
}

int main(int argc, char* argv[]) {
    if (argc == 1) //checks whether the command line is empty
        printf("Error: enter two arguments");
    else if( argc < 3 ) {
        printf("Enter two Arguments");}
    else if (argc == 2){ //checks command line argument
        printf("Correct Argument");}
    FILE *fp_fruit;
    FILE *fp_dairy;  // two files for reading
    fp_fruit = fopen(argv[1],"r");
    fp_dairy = fopen(argv[2],"r");
    int lines;
    if(count_line(fp_dairy) < 2 || count_line(fp_fruit) < 2 || count_line(fp_fruit) != count_line(fp_dairy)){
        return 0;
    }
    char fruit_headers[100][200];
    char dairy_headers[100][200];
    char fruit_day[100];
    char dairy_day[100];
    lines = count_line(fp_fruit) -1;  // count the lines in txt file
    int* fruit_sales = (int*)malloc(sizeof(int) * lines * 5 );
    int* dairy_sales = (int*)malloc(sizeof(int) * lines * 5 );
    rewind(fp_fruit);
    rewind(fp_dairy);  // read the file from the start
    fscanf(fp_fruit, "%s %s %s %s %s %s", fruit_headers[0], fruit_headers[1], fruit_headers[2], fruit_headers[3], fruit_headers[4], fruit_headers[5]);
    fscanf(fp_dairy, "%s %s %s %s %s %s", dairy_headers[0], dairy_headers[1], dairy_headers[2], dairy_headers[3], dairy_headers[4], dairy_headers[5]);
    for(int i = 0; i < lines ; i++){
        fscanf(fp_fruit, "%s %d %d %d %d %d", fruit_day, &fruit_sales[5 * i], &fruit_sales[5 * i + 1], &fruit_sales[5 * i + 2], &fruit_sales[5 * i + 3], &fruit_sales[5 * i + 4]);
    }
    for(int i = 0; i < lines ; i++){
        fscanf(fp_dairy, "%s %d %d %d %d %d", dairy_day, &dairy_sales[5 * i], &dairy_sales[5 * i + 1], &dairy_sales[5 * i + 2], &dairy_sales[5 * i + 3], &dairy_sales[5 * i + 4]);
    }
    display_sales(fruit_headers, fruit_sales, lines);
    display_sales(dairy_headers, dairy_sales, lines);
    free(fruit_sales);
    free(dairy_sales);
    fclose(fp_fruit);
    fclose(fp_dairy);
    return 0;
}




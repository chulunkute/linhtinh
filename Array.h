#include<string.h>
#include<stdio.h>
#include <stdlib.h>
#include<windows.h>

#define MAX_COUNT 10000

//dinh nghia ADT
typedef struct FloatArray{
	float *arr;
	int count;
}FloatArray;

//ham yeu cau ng dung nhap dung du lieu la so trong pham vi can tim
int getInputFromKeyBoard(int min, int max, char* requirement){
	int check,
		set;
	do{
		fflush(stdin);               //phong truong hop du lieu nhap vao la chu, nen can xoa bo dem
		printf(requirement);
		check = scanf("%d", &set);  //bien check tra ve gia tri 0 neu du lieu nhap vao khac so
 		printf("");
		if (set < min || set > max || check == 0) printf("Nhap loi, moi nhap lai\n");
	}while (set < min || set > max || check == 0);
	return set;
}
//ham tao mang tu ban phim
void creatArrayFromKeyBoard(FloatArray *obj){
	obj->count = getInputFromKeyBoard(0, MAX_COUNT, "Nhap so luong phan tu: ");
	obj->arr = (float*) malloc(obj->count * sizeof(float));  //cap phat bo nho cho mang
	int i, check;
	//nhap gia tri trong mang
	for(i = 0; i < obj->count; i++)
	   //cac cau lenh trong do while bat buoc du lieu nhap vao phai la so nhu ham getInputFromKeyBoard
		do{
			fflush(stdin);
			printf("Nhap phan tu thu %d: ", i + 1);
			check = scanf("%f", &obj->arr[i]);        
			printf("");
			if (check == 0) printf("Nhap loi, moi nhap lai\n");
		}while (check == 0);
}
//ham tao mang tu file
void creatArrayFromFile(FloatArray *obj, char* fileName){
	FILE *f;
    f = fopen(fileName,"rt");
   	fscanf(f,"%d",&obj->count);
   	obj->arr = (float*) malloc(obj->count *sizeof(float));
   	int i;
   	for(i = 0;i < obj->count;i++)
       	fscanf(f,"%f",&obj->arr[i]);
  	fclose(f);
}
//ham in mang ra man hinh
void printArrayToConsole(FloatArray *obj){
	int i;
	for(i = 0; i < obj->count; i++)
		printf("%.2f ", obj->arr[i]);
	printf("\n");
}
//ham in mang ra file 
void printArrayToFile(FloatArray *obj, char *fileName){
	FILE *f;
    f = fopen(fileName,"wt");
   	fprintf(f,"%d ",obj->count);
   	int i;
   	for(i = 0; i < obj->count; i++)
       	fprintf(f,"%.2f ",obj->arr[i]);
   	fclose(f);
}
//ham thay doi so luong phan tu cua mang
void changeArray_count(FloatArray *obj){
	int length = getInputFromKeyBoard(0, MAX_COUNT, "Nhap so luong phan tu: ");
	int i,
		check;
	//neu do dai moi lon hon do dai cu thi yeu cau nhap cac phan tu moi, nguoac lai thi gan cac phan tu duoi  = 0	
	if (length > obj->count){
		obj->arr = (float*) realloc(obj->arr, length * sizeof(float)); //ham thay doi bo nho da cap phat
		for (i = obj->count; i < length; i++)
			do{
				fflush(stdin);
				printf("Nhap phan tu thu %d: ", i + 1);
				check = scanf("%f", &obj->arr[i]);
				printf("");
				if (check == 0) printf("Nhap loi, moi nhap lai\n");
			}while (check == 0);
    } 
	else 
		for (i = length; i < obj->count; i++)
			obj->arr[i] = 0;
	obj->count = length;	
}
//ham thay doi gia tri cac phan tu da co trong mang
void changeArray_value(FloatArray *obj){
	int location = getInputFromKeyBoard(1, obj->count, "Nhap vi tri: "),
		check;
	float temp;
	do{
		fflush(stdin);
		printf("Nhap gia tri phan tu muon thay: ");
		check = scanf("%f", &temp);
		printf("");
		if (check == 0) printf("Ban hay nhap vao mot so thuc");
	}while (check == 0);
	obj->arr[location - 1] = temp;
}

void changeArray(FloatArray *obj){
	printf("Ban muon thay doi thong tin gi (1/2):\n");
	printf("1. So luong phan tu           2. Gia tri phan tu trong mang\n");
	int feature = getInputFromKeyBoard(1, 2, "Nhap tinh nang: ");
	switch(feature){
		case 1: 
			changeArray_count(obj);
			break;
		case 2:
			changeArray_value(obj);
			break;
	}
}

void swap(float *a, float *b){
	float c = *a;
	*a = *b;
	*b = c;
}
//sap xep noi bot
void bubbleSort(FloatArray *obj){
	int i, j;
	for (i = 0; i < obj->count - 1; i++)
		for (j = i + 1; j < obj->count; j++)	
			if (obj->arr[i] > obj->arr[j]) swap(&obj->arr[i], &obj->arr[j]);
}
//sap xep chon
void selectionSort(FloatArray *obj){
	int i, j, min;
	for (i = 0; i < obj->count - 1; i++){
		min = i;
		for (j = i + 1; j < obj->count; j++){
			if (obj->arr[j] < obj->arr[min])
				min = j;
		}
		swap(&obj->arr[i], &obj->arr[min]);
	}
}
//sap xep chen
void insertionSort(FloatArray *obj){
	int i, j, last;
	for (i = 1; i <= obj->count - 1; i++){
		j = i;
		while (j >= 1  && obj->arr[j-1] > obj->arr[j]){
			swap(&obj->arr[j-1], &obj->arr[j]);
			j--;
		}
	
	}
}
//tim chi so phan tu max dau tien
int findMaxFirstIndex(FloatArray *obj){
	int i, 
		maxFirstIndex = 0;
	float max = obj->arr[0];
	for (i = 1; i < obj->count; i++)
		if (obj->arr[i] > max){
			max = obj->arr[i];
			maxFirstIndex = i;
		}
	return maxFirstIndex;
}
//tim chi so phan tu min dau tien
int findMinFirstIndex(FloatArray *obj){
	int i, 
		minFirstIndex = 0;
	float min = obj->arr[0];
	for (i = 1; i < obj->count; i++)
		if (obj->arr[i] < min){
			min = obj->arr[i];
			minFirstIndex = i;
		}
	return minFirstIndex;
}
//ham in ra phan tu max lon nhat va cac vi tri cua no ra man hinh
void printMaxToConsole(FloatArray *obj){
	int maxFirstIndex = findMaxFirstIndex(obj);
	printf("Gia tri lon nhat cua mang: %.2f\n", obj->arr[maxFirstIndex]);
	int i;
	printf("Vi tri cua gia tri do la: ");
	//tu vi tri phan tu lon nhat dau tien duyet den cuoi de tim nhung phan tu max (neu co con lai)
	for (i = maxFirstIndex; i < obj->count; i++)
		if (obj->arr[i] == obj->arr[maxFirstIndex]) 
			printf("%d ", i + 1);
	printf("\n");
}
//ham in ra phan tu min lon nhat va cac vi tri cua no ra man hinh
void printMinToConsole(FloatArray *obj){
	int minFirstIndex = findMinFirstIndex(obj);
	printf("Gia tri nho nhat cua mang: %.2f\n", obj->arr[minFirstIndex]);
	int i;
	printf("Vi tri cua gia tri do la: ");
	for (i = minFirstIndex; i < obj->count; i++)
		if (obj->arr[i] == obj->arr[minFirstIndex])
			printf("%d ", i + 1);
	printf("\n");
}
//ham in ra phan tu lon nhat va cac vi tri cua no ra file
void printMaxToFile(FloatArray *obj, char *fileName){
	int maxFirstIndex = findMaxFirstIndex(obj);
	FILE *f;
	f = fopen(fileName,"wt");
	fprintf(f, "Gia tri lon nhat trong mang la: %.2f \n", obj->arr[maxFirstIndex]);
	fprintf(f, "Vi tri cua gia tri do la: ");
	int i;
	for (i = maxFirstIndex; i < obj->count; i++)
		if (obj->arr[i] == obj->arr[maxFirstIndex]) fprintf(f, "%d ", i + 1);
	fclose(f);
}
//ham in ra phan tu nho nhat va cac vi tri cua no ra file
void printMinToFile(FloatArray *obj, char *fileName){
	int minFirstIndex = findMinFirstIndex(obj);
	FILE *f;
	f = fopen(fileName,"wt");
	fprintf(f, "Gia tri nho nhat trong mang la: %.2f \n", obj->arr[minFirstIndex]);
	fprintf(f, "Vi tri cua gia tri do la: ");
	int i;
	for (i = minFirstIndex; i < obj->count; i++)
		if (obj->arr[i] == obj->arr[minFirstIndex]) fprintf(f, "%d ", i + 1);
	fclose(f);
}
//ham tim trung binh cua mang
float findAverage(FloatArray *obj){
	int i, 
		s = 0;
	for (i = 0; i < obj->count; i++)
		s+= obj->arr[i];
	return s / obj->count;
}
//ham in trung binh ra man hinh
void printAverageToConsole(FloatArray *obj){
	printf("Gia tri trung binh cua mang: %.2f\n", findAverage(obj));
}
//ham in trung binh ra file
void printAverageToFile(FloatArray *obj, char *fileName){
	FILE *f;
	f = fopen(fileName, "wt");
	fprintf(f, "Gia tri trung binh cua mang: %.2f\n", findAverage(obj));
	fclose(f);
	
}
//ham tra ve gia tri tuyet doi
float absolute(float x){
	return (x > 0? x : -x);
} 
//ham tim do lech
float findDeviation(FloatArray *obj){
	int firstIndex = getInputFromKeyBoard(1, obj->count, "Nhap vi tri thu nhat: ");//nhap vi tri thu nhat tu ban phim
	int secondIndex = getInputFromKeyBoard(1, obj->count, "Nhap vi tri thu hai: ");//nhap vi tri thu hat tu ban phim
	float deviation = obj->arr[firstIndex - 1] - obj->arr[secondIndex - 1];
	return abs(deviation);
}
//in do lech ra man hinh
void printDeviationToConsole(FloatArray *obj){
	float deviation = findDeviation(obj);
	printf("Do lech giua 2 phan tu la: %.2f\n", deviation);
}
//in do lech ra file
void printDeviationToFile(FloatArray *obj, char *fileName){
	float deviation = findDeviation(obj);
	FILE *f;
	f = fopen(fileName, "wt");
	fprintf(f, "Do lech giua 2 phan tu la: %.2f\n", deviation);
	fclose(f);
}
//tim do lech trung binh
float findAverageDeviation(FloatArray *obj){
	float average = findAverage(obj); //tim trung binh cong
	float s = 0;
	int i;
	for (i = 0; i < obj->count; i++)
		s+= absolute(obj->arr[i] - average);  //tinh tong do lech giua cac phan tu voi trung binh cong
	return s / obj->count;  //tra ve do lech trung binh
}
//ham in do lech trung binh ra man hinh
void printAverageDeviationToConsole(FloatArray *obj){
	printf("Do lech trung binh giua cac phan tu la: %.2f\n", findAverageDeviation(obj));	
}
//ham in do lech trung binh ra file
void printAverageDeviationToFile(FloatArray *obj, char *fileName){
	FILE *f;
	f = fopen(fileName, "wt");
	fprintf(f, "Do lech trung binh giua cac phan tu la: %.2f\n", findAverageDeviation(obj));
	fclose(f);
}
//ham tim kiem tuan tu tra ve vi tri dau tien bang gia tri can tim
int sequentialSearch(FloatArray *obj, float search){
	int i;
	for (i = 0; i < obj->count; i++)
		if (obj->arr[i] == search) return i;
	return -1;	
}
//ham tim kiem nhi phan
int binarySearch(FloatArray *obj, float search){
	int first = 0,
   		last = obj->count - 1,
  		middle = (first + last) / 2;
 	int j = -1;
  	while (first <= last){
    	if (obj->arr[middle] < search)
        	first = middle + 1;    
      	else 
		  if (obj->arr[middle] == search){
		  	j = middle;
		  	break;
		  }			   
          else
        	    last = middle - 1;
    	middle = (first + last)/2;
	}
	return j;
}
//ham sao chep mang cu sang mang moi, de khi tinh toan thoi gian cac thuat toan ta tinh tren mang ban sao
//cho mat du lieu mang cu
FloatArray *tempFloatArray(FloatArray *obj){
	FloatArray *temp = (FloatArray*) malloc(sizeof(FloatArray));
	temp->count = obj->count;
	temp->arr = (float*) malloc(temp->count*sizeof(float));
	int i;
	for (i = 0; i < temp->count; i++)
		temp->arr[i] = obj->count;
	return temp;
}
//ham tinh thoi gian thuat toan sap xep noi bot
void timeCalculatingBubbleSort(FloatArray *obj){
	LARGE_INTEGER   freq, start, end;
	FloatArray *temp = tempFloatArray(obj); //sao chep mang
	QueryPerformanceFrequency(&freq);	//hang so thoi gian
	QueryPerformanceCounter(&start);   //danh dau thoi diem  bat dau tinh theo hang so thoi gian tren
	bubbleSort(temp);					
    QueryPerformanceCounter(&end);  //danh dau thoi diem ket thuc tinh theo hang so thoi gian tren
    free(temp);
	double counter =  (double)(end.QuadPart - start.QuadPart) / freq.QuadPart;  //lay thoi diem dau tru thoi diem cuoi roi chia hang so thoi gian
	printf("Do phuc tap: O(n^2)\n");
   	printf("Thoi gian tinh toan= %.7lf\n", counter);	
}
//ham tinh toan thoi gian sap xep chen
void timeCalculatingInsertionSort(FloatArray *obj){
	LARGE_INTEGER   freq, start, end;
	FloatArray *temp = tempFloatArray(obj);
	QueryPerformanceFrequency(&freq);	
	QueryPerformanceCounter(&start);
	insertionSort(temp);
    QueryPerformanceCounter(&end);
    free(temp);
	double counter = (double)(end.QuadPart - start.QuadPart) / freq.QuadPart;
	printf("Do phuc tap: O(n^2)\n");
   	printf("Thoi gian tinh toan= %.7lf\n", counter);
}
//ham tinh toan thoi gian sap xep chon
void timeCalculatingSelectionSort(FloatArray *obj){
	LARGE_INTEGER   freq, start, end;
	FloatArray *temp = tempFloatArray(obj);
	QueryPerformanceFrequency(&freq);	
	QueryPerformanceCounter(&start);
	selectionSort(temp);
    QueryPerformanceCounter(&end);
    free(temp);
	double counter = (double)(end.QuadPart - start.QuadPart) / freq.QuadPart;
	printf("Do phuc tap: O(n^2)\n");
   	printf("Thoi gian tinh toan= %.7lf\n", counter);
}
//ham tinh thoi gian tim kiem tuan tu
void timeCalculatingSequentialSearch(FloatArray *obj){
	LARGE_INTEGER   freq, start, end;
	FloatArray *temp = tempFloatArray(obj);
	float search;
	printf("Nhap gia tri phan tu muon tim: ");
	scanf("%f", &search);
	printf("");
	QueryPerformanceFrequency(&freq);	
	QueryPerformanceCounter(&start);
	sequentialSearch(temp, search);
    QueryPerformanceCounter(&end);
    free(temp);
	double counter = (double)(end.QuadPart - start.QuadPart) / freq.QuadPart;
	printf("Do phuc tap: O(n)\n");
   	printf("Thoi gian tinh toan= %.7lf\n", counter);	
}
//ham tinh thoi gian tim kiem nhi phan
void timeCalculatingBinarySearch(FloatArray *obj){
	LARGE_INTEGER   freq, start, end;
	FloatArray *temp = tempFloatArray(obj);
	selectionSort(temp);  //phai sap xep truoc thi thuat toan tim kiem nhi phan moi dung
	float search;
	printf("Nhap gia tri phan tu muon tim:");
	scanf("%f", &search);
	printf("\nThuat toan thuc hien khi mang da dc sap xep\n");
	QueryPerformanceFrequency(&freq);	
	QueryPerformanceCounter(&start);
	binarySearch(temp, search);
    QueryPerformanceCounter(&end);
    free(temp);
	double counter = (double)(end.QuadPart - start.QuadPart) / freq.QuadPart;
	printf("Do phuc tap: O(logn)\n");
   	printf("Thoi gian tinh toan= %.7lf\n", counter);	
}
//ham in ra cac ham can tinh toan thoi gian
void printTimeCalculatingFunction(FloatArray *obj){
	printf("Ban muon tinh thoi gian cua giai thuat nao: \n");
	printf("1. BubbleSort\n");
	printf("2. InsertionSort\n");
	printf("3. SelectionSort\n");
	printf("4. SequentialSearch\n");
	printf("5. BinarySearch\n");
	int feature = getInputFromKeyBoard(1, 5, "Nhap tinh nang: ");
	switch(feature){
		case 1: timeCalculatingBubbleSort(obj); break;
		case 2: timeCalculatingInsertionSort(obj); break;
		case 3: timeCalculatingSelectionSort(obj); break;
		case 4: timeCalculatingSequentialSearch(obj); break;
		case 5: timeCalculatingBinarySearch(obj); break;
	}
}



#include"Array.h"

void menu(FloatArray *obj);
//menu con 1: xem nhan thong tin tu dau
int subMenu1(){
	int i;
	printf("Ban muon nhap thong tin tu dau (1/2/3)?\n");
	printf("1. Ban phim		2. File IO		3. Quay lai menu chinh\n");
	i = getInputFromKeyBoard(1, 3, "Nhap tinh nang: ");
	return i;
}
//menu con 2: xem xuat thong tin ra dau
int subMenu2(){
	int i;
	printf("Ban muon xuat thong tin ra dau (1/2/3)?\n");
	printf("1. Man hinh		2. File IO		3. Quay lai menu chinh\n");
	i = getInputFromKeyBoard(1, 3, "Nhap tinh nang: ");
	return i;
}
//menu quay lai menu chinh				
void backMenu(FloatArray *obj){
	char i;
	fflush(stdin);
	printf("Ban muon quay lai menu chinh khong(an Y hoac y de dong y)?\n");
	scanf("%c",&i);
	if (i == 'Y' || i == 'y') menu(obj);
	else {
		printf("Chuong trinh ket thuc\n");
		return;
	}
}
//ham nhan ten file cho viec nhap xuat du lieu
char* getFileName(){
	char* fileName = (char*) malloc(sizeof(char));
	fflush(stdin);
	printf("Nhap ten file:\n");
	gets(fileName);
	return fileName;
}
//ham kiem tra mang da khoi tao hay chua
int checkInit(FloatArray *obj){
	if (obj->count < 0){
		printf("Mang chua khoi tao. Vui long khoi tao\n");
		backMenu(obj);
		return 0;
	}else return 1;
}
//chuc nang 1: khoi tao ADT
void feature1(FloatArray *obj){
	int subFeature = subMenu1();
	switch(subFeature){
		case 1: 
			creatArrayFromKeyBoard(obj);
			printf("Mang sau khi khoi tao: \n");
			printArrayToConsole(obj);
			backMenu(obj);
			break;
		case 2:
			creatArrayFromFile(obj, getFileName());
			printf("Mang sau khi khoi tao: \n");
			printArrayToConsole(obj);
			backMenu(obj);
			break;
			
		case 3:
			menu(obj);
			break;
	}
}
//chuc nang 2: thay doi mang
void feature2(FloatArray *obj){
	if (checkInit(obj) == 1){
		printf("Mang truoc khi sua doi:\n");
		printArrayToConsole(obj);
		changeArray(obj);
		int subFeature = subMenu2();
		switch(subFeature){
			case 1:
				printf("Mang sau khi sua doi:\n");
				printArrayToConsole(obj);
				backMenu(obj);
				break;
			case 2:
				printArrayToFile(obj, getFileName());
				backMenu(obj);
				break;
			case 3: 
				menu(obj);
				break;
		}
	}
}
//chuc nang 3: sap xep mang bang sap xep noi bot
void feature3(FloatArray *obj){
	if (checkInit(obj) == 1){
		printf("Mang truoc khi sap xep:\n");
		printArrayToConsole(obj);
		bubbleSort(obj);
		int subFeature = subMenu2();
		switch(subFeature){
			case 1:
				printf("Mang sau khi sap xep:\n");
				printArrayToConsole(obj);
				backMenu(obj);
				break;
			case 2:
				printArrayToFile(obj, getFileName());
				backMenu(obj);
				break;
			case 3: 
				menu(obj);
				break;
		}
	}
}
//chuc nang 4: sap xep mang theo thuat toan sap xep chen
void feature4(FloatArray *obj){
	if (checkInit(obj) == 1){
		printf("Mang truoc khi sap xep:\n");
		printArrayToConsole(obj);
		insertionSort(obj);
		int subFeature = subMenu2();
		switch(subFeature){
			case 1:
				printf("Mang sau khi sap xep:\n");
				printArrayToConsole(obj);
				backMenu(obj);
				break;
			case 2:
				printArrayToFile(obj, getFileName());
				backMenu(obj);
				break;
			case 3: 
				menu(obj);
				break;
		}
	}
}
//chuc nang 5:sap xep mang theo thuat toan sap xep chon
void feature5(FloatArray *obj){
	if (checkInit(obj) == 1){
		printf("Mang truoc khi sap xep:\n");
		printArrayToConsole(obj);
		selectionSort(obj);
		int subFeature = subMenu2();
		switch(subFeature){
			case 1:
				printf("Mang sau khi sap xep:\n");
				printArrayToConsole(obj);
				backMenu(obj);
				break;
			case 2:
				printArrayToFile(obj, getFileName());
				backMenu(obj);
				break;
			case 3: 
				menu(obj);
				break;
		}
	}
}
//chuc nang 6: dua ra phan tu lon nhat va cac vi tri cua chung
void feature6(FloatArray *obj){
	if (checkInit(obj) == 1){
		printf("Mang hien tai:\n");
		printArrayToConsole(obj);
		int subFeature = subMenu2();
		switch(subFeature){
			case 1:
				printMaxToConsole(obj);
				backMenu(obj);
				break;
			case 2:
				printMaxToFile(obj, getFileName());
				backMenu(obj);
				break;
			case 3:
				menu(obj);
				break;
		}
	}
}
//chuc nang 7: dua ra phan tu nho nhat va cac vi tri cua chung
void feature7(FloatArray *obj){
	if (checkInit(obj) == 1){
		printf("Mang hien tai:\n");
		printArrayToConsole(obj);
		int subFeature = subMenu2();
		switch(subFeature){
			case 1:
				printMinToConsole(obj);
				backMenu(obj);
				break;
			case 2:
				printMinToFile(obj, getFileName());
				backMenu(obj);
				break;
			case 3:
				menu(obj);
				break;
		}
	}
}
//chuc nang 8: tinh trung binh cong
void feature8(FloatArray *obj){
	if (checkInit(obj) == 1){
		printf("Mang hien tai:\n");
		printArrayToConsole(obj);
		int subFeature = subMenu2();
		switch(subFeature){
			case 1:
				printAverageToConsole(obj);
				backMenu(obj);
				break;
			case 2:
				printAverageToFile(obj, getFileName());
				backMenu(obj);
				break;
			case 3:
				menu(obj);
				break;
		}
	}
}
//chuc nang 9: tinh do lech giua 2 phan tu bat ki
void feature9(FloatArray *obj){
	if (checkInit(obj) == 1){
		printf("Mang hien tai:\n");
		printArrayToConsole(obj);
		int subFeature = subMenu2();
		switch(subFeature){
			case 1:
				printDeviationToConsole(obj);
				backMenu(obj);
				break;
			case 2:
				printDeviationToFile(obj, getFileName());
				backMenu(obj);
				break;
			case 3:
				menu(obj);
				break;
		}
	}
}
//chuc nang 10: chuc nang tinh do lech trung binh
void feature10(FloatArray *obj){
	if (checkInit(obj) == 1){
		printf("Mang hien tai:\n");
		printArrayToConsole(obj);
		int subFeature = subMenu2();
		switch(subFeature){
			case 1:
				printAverageDeviationToConsole(obj);
				backMenu(obj);
				break;
			case 2:
				printAverageDeviationToFile(obj, getFileName());
				backMenu(obj);
				break;
			case 3:
				menu(obj);
				break;
		}
	}
}
//chuc nang 11: thuat toan tim kiem tuan tu
void feature11(FloatArray *obj){
	if (checkInit(obj) == 1){
		printf("Mang hien tai:\n");
		printArrayToConsole(obj);
		float search;
		int subFeature = subMenu2();
		switch(subFeature){
			case 1:
				printf("Nhap gia tri can tim:\n");
				scanf("%f",&search);
				printf("Vi tri phan tu can tim: %d", sequentialSearch(obj, search) + 1);
				printf("\n");
				backMenu(obj);
				break;
			case 2:
				printf("Nhap gia tri can tim: ");
				scanf("%f",&search);
				FILE *f;
				f = fopen(getFileName(),"wt");
				fprintf(f, "Vi tri phan tu can tim: %d", sequentialSearch(obj, search) + 1);
				fclose(f);
				backMenu(obj);
				break;
			case 3:
				menu(obj);
				break;
		}
	}
}
//chuc nang 12: thuat toan tim kiem nhi phan
void feature12(FloatArray *obj){
	if (checkInit(obj) == 1){
		printf("Mang hien tai:\n");
		printArrayToConsole(obj);
		float search;
		int subFeature = subMenu2();
		switch(subFeature){
			case 1:
				printf("Nhap gia tri can tim:\n");
				scanf("%f",&search);
				printf("Thuat toan duoc thuc hien sau khi mang duoc sap xep");
				selectionSort(obj);
				printf("Vi tri phan tu can tim: %d", sequentialSearch(obj, search) + 1);
				printf("\n");
				backMenu(obj);
				break;
			case 2:
				printf("Nhap gia tri can tim: ");
				scanf("%f",&search);
				printf("Thuat toan duoc thuc hien sau khi mang duoc sap xep");
				selectionSort(obj);
				FILE *f;
				f = fopen(getFileName(),"wt");
				fprintf(f, "Vi tri phan tu can tim: %d", sequentialSearch(obj, search) + 1);
				backMenu(obj);
				fclose(f);
				break;
			case 3:
				menu(obj);
				break;
		}
	}
}
//chuc nang 13: tinh toan thoi gian cac thuat toan
void feature13(FloatArray *obj){
	if (checkInit(obj) == 1){
		printTimeCalculatingFunction(obj);
		backMenu(obj);
	}
}
//chuc nang 14: tra bo nho, ket thuc chuong trinh
void feature14(FloatArray *obj){
	free(obj);
	printf("Chuong trinh ket thuc\n");
}

void menu(FloatArray *obj){
	printf("\n");
	system("cls");//ham xoa man hinh
	printf("========MENU=======\n");
	printf("1. Khoi tao ham moi\n");
	printf("2. Thay doi gia tri cua mang\n");
	printf("3. Sap xep phan tu bang BubbleSort\n");
	printf("4. Sap xep phan tu bang InsertSort\n");
	printf("5. Sap xep phan tu bang SelectionSort\n");
	printf("6. Tim gia tri lon nhat va cac vi tri cua gia tri lon nhat\n");
	printf("7. Tim gia tri nho nhat va cac vi tri cua gia tri nho nhat\n");
	printf("8. Gia tri trung binh cac phan tu trong mang\n");
	printf("9. Do lech gia tri giua 2 vi tri biet truoc trong mang\n");
	printf("10. Do lech trung binh cac phan tu trong mang\n");
	printf("11. Tim kiem tuan tu SequentialSearch\n");
	printf("12. Tim kiem nhi phan BinarySort\n");
	printf("13. Thoi gian thuc hien cac ham\n");
	printf("14. Ket thuc chuong trinh\n");
	printf("===================\n");
	int feature = getInputFromKeyBoard(1, 14, "Nhap tinh nang: ");
	switch(feature){
		case 1:
			feature1(obj);break;
		case 2:
			feature2(obj);break;
		case 3:
			feature3(obj);break;
		case 4:
			feature4(obj);break;
		case 5:
			feature5(obj);break;
		case 6:
			feature6(obj);break;
		case 7:
			feature7(obj);break;
		case 8:
			feature8(obj);break;
		case 9:
			feature9(obj);break;
		case 10:
			feature10(obj);break;
		case 11:
			feature11(obj);break;
		case 12:
			feature12(obj);break;
		case 13:
			feature13(obj);break;
		case 14:
			feature14(obj);break;		
	}
}

int main(){
	FloatArray *obj = (FloatArray*) malloc(sizeof(FloatArray));
	obj->count = -1;
    menu(obj);
	return 1;
}


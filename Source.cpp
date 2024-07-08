#include <stdio.h>

int main() {
	int value,x,y;
	printf("input value(0 <= x <= y < 2 31): ");
	
	printf("\ninput x: ");
	scanf_s("%d", &x);
	printf("\ninput y: ");
	scanf_s("%d", &y);

	value =y-x+1 ;
	int acumulation=0;
	int count = 0;
	int count_avarage=0;
	int acumulation_old = 0;
	for (int j = 1;;j+=2) {
		//printf("\nqq%d", j);
		acumulation = 0;
		count_avarage = 0;
		for (int i = 1; i <= j; i++) {
			
			if ((j+1) / 2 >= i) {
				acumulation += i;
				//printf("\nacumulation%d", acumulation);
				count_avarage++;
			}
			else {
				
				acumulation += (acumulation - i+1);
				break;
			}


		}
		if (acumulation+1 == value) {
			
			//printf("\n\033[31mEXit1 %d", acumulation);
			count = j; // -1
			break;
		}
		else if (acumulation + 1 > value) {
			acumulation = acumulation - count_avarage - (count_avarage - 1);
			count_avarage--;
			//printf("\nEXit2 %d", acumulation);
			count = j-2; // -1
			break;
		}
	}

	int  diferent = value - (acumulation+1) ;
	//printf("\ndiferent %d ", diferent);
	//printf("\ncount_avarage %d\n ", count_avarage);
	//printf("\nacumulation %d\n ", acumulation);

	if (diferent == 0) {
		count;
	}
	else if (diferent == count_avarage) {
		count++;
	}
	else if (diferent > count_avarage) {
		count += 2;
	}
	else if (diferent < count_avarage) {
		count ++;
	}

	printf("\nThe minimum number of steps required to go from x to y : %d ", count);


	return 0;
}
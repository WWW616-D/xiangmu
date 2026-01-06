#include"works.h"
#include<math.h>
#include<string.h>
#define MIN 1e-6
int solution_number=0;
char solution[1000][30];
void try_to_solve(float* num,char** num_str)
{
	if (fabs(num[0]-24)<MIN)
	{
		int index = 0;
		char* truesolution = (char*)malloc(30);
		char* p = num_str[0];
		int flag = 0;
		int len = strlen(num_str[0]);
		
		while(*p=='('&&*(p+len-1)==')')
		{
			int count = 1;
			char* q = p+1;
			while(*q!='(')
			{
				if (*q==')'&&q<p+len)
				{
					count=0;
					break;
				}
				q++;
			}
			q = p + len - 2;
			while (*q != ')'&&q>p)
			{
				if (*q == '(')
				{
					count=0;
					break;
				}
				q--;
			}
			if (count)
			{
				p++;
				len--;
			}
			else
				break;
		}
		while(p<num_str[0]+len)
		{
			if (*p == '.')
			{
				flag = 1;
				p++;
				continue;
			}
			if (flag==1&&*p=='0')
			{
				p++;
				continue;
			}
			else
			{
				flag = 0;
			}
			truesolution[index] = *p;
			index++;
			p++;
		}
		truesolution[index] = '\0';
		for (int i=0;i<solution_number;i++)
		{
			if (strcmp(truesolution, solution[i]) == 0)
				return;
		}
		strcpy(solution[solution_number++], truesolution);
		printf("24=");
		printf("%s\n",truesolution);
	}
	return;
}
void find(float* num,int len,char** num_str)
{
	if (len >= 2)
	{
		for (int i = 0; i < len; i++)
		{
			for (int j = 0; j < len; j++)
			{
				int index = 0;
				if (j == i)
					continue;
				float* newnum = (float*)calloc(len - 1, sizeof(float));
				char** newnum_str = (char**)malloc((len - 1) * sizeof(char*));
				for (int p = 0; p < len - 1; p++)
				{
					newnum_str[p] = (char*)malloc(50*sizeof(char));
				}
				for (int k = 0; k < len; k++)
				{
					if (k == j || k == i)
						continue;
					newnum[index] = num[k];
					strcpy(newnum_str[index], num_str[k]);
					index++;
				}
				newnum[len - 2] = num[i] + num[j];
				snprintf(newnum_str[len - 2], 50, "(%s+%s)",num_str[i],num_str[j]);
				find(newnum, len - 1,newnum_str);

				newnum[len - 2] = num[i] - num[j];
				snprintf(newnum_str[len - 2], 50, "(%s-%s)", num_str[i], num_str[j]);
				find(newnum, len - 1, newnum_str);
			
				newnum[len - 2] = num[j] - num[i];
				snprintf(newnum_str[len - 2], 50, "(%s-%s)", num_str[j], num_str[i]);
				find(newnum, len - 1, newnum_str);
			
				newnum[len - 2] = num[i] * num[j];
				snprintf(newnum_str[len - 2], 50, "%s*%s", num_str[i], num_str[j]);
				find(newnum, len - 1, newnum_str);

				if (fabs(num[j])>MIN)
				{
					newnum[len - 2] = num[i] / num[j];
					snprintf(newnum_str[len - 2], 50, "%s/%s", num_str[i], num_str[j]);
					find(newnum, len - 1, newnum_str);
				}

				if (fabs(num[i]) > MIN)
				{
					newnum[len - 2] = num[j] / num[i];
					snprintf(newnum_str[len - 2], 50, "%s/%s", num_str[j], num_str[i]);
					find(newnum, len - 1, newnum_str);
				}
			}
		}
		return;
	}
	if (len==1)
	{
		try_to_solve(num, num_str);
		return;
	}
}
void TwentyFourPoint()
{
	printf("你好,欢迎来到二十四点\n");
	printf("给出任意四个整数，你将得到它们全部的24点解法:\n");
	float num[4];
	for (int i=0;i<4;i++)
	{
		scanf("%f", &num[i]);
	}
	char** num_str = (char**)malloc(4 * sizeof(char*));
	for (int i = 0; i < 4; i++)
	{
		num_str[i] = (char*)malloc(20*sizeof(char));
		snprintf(num_str[i], 20, "%f", num[i]);
	}
	find(num,4,num_str);
}
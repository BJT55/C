#include <stdio.h>
#include <assert.h>



/*
int main()
{
	int a = 20;
	int b = -10;
}
*/

//��������������һ������ֵ
//�Զ���������һ������ֵ
//����ָ������ֵ
//������Ч����ֵ    #pragma pack��2�� ��2�ֽڶ��� 


/*
void main(int argc,char *argv[])  //argc:argument count   argv:argument value
{}
*/

//    atoi()  ���ַ�����ת��Ϊ������

//   strtok

/*
//   strstr
char *my_strstr(const char *str1, const char *str2)
{
	assert(str1 != NULL);
	assert(str2 != NULL);
	if (*str2 == '\0')
	{
		return (char*)str1;
	}
	while (*str1 != '\0')
	{
		const char*p1 = str1;
		const char*p2 = str2;
		while (*p2 != '\0')
		{
			if (*p1 != *p2)
			{
				break;
			}
			else
			{
				*p1++;
				*p2++;
			}
		}
		if (*p2 == '\0')
		{
			return (char*)str1;
		}
		str1++;
	}
}
int main()
{
	char *str1 = "pineapple";
	char *str2 = "apple";
	printf("%s\n", my_strstr(str1, str2));
	return 0;
}
*/


//�ڴ��������
/*
	memset();	�ڴ����á�����ʼ������
	memcpy();	����  �������ڴ渲�����⣬�ڴ��ص����⣩
	memcmp();	�Ƚϴ�С
	memmove();	  �ڴ��ƶ�
*/

//memcpy
/*
void *my_memcpy(void *dst, const void *src, size_t count)
{
	assert(dst);
	assert(src);
	char* pdst = (char*)dst;
	const char*psrc = (const char*)src;
	while (count--)
	{
		*pdst++ = *psrc++;
	}
	return dst;
}
int main()
{
	char a1[10] = "abcdefghi";
	char a2[10] = "abcdefghi";
	char a3[10] = { 0 };
	my_memcpy(a1 + 2, a1, 6);
	my_memcpy(a3, a1, 6);
	printf("�ڴ渲�ǣ�%s\n", a1 + 2);
	printf("������%s\n", a3);
	return 0;
}
*/



/*
//memmove
void *my_memmove(void *dst, const void *src, size_t count)
{
	void *ret = dst;
	void *psrc =(void*) src;
	void *pdst =(void*)dst;
	if (pdst <= psrc || (char *)psrc + count)
	{
		while (count--)
		{
			*(char*)pdst = *(char*)psrc;
			pdst = (char*)pdst + 1;
			psrc = (char*)psrc + 1;
		}
	}
	else
	{
		pdst = (char*)pdst + count - 1;
		psrc = (char*)psrc + count - 1;
		while (count--)
		{
			*(char*)pdst = *(char*)psrc;
			pdst = (char*)pdst - 1;
			psrc = (char*)psrc - 1;
		}
	}
	return ret;
}
int main()
{
	char a1[10] = "abcdefg";
	char a2[10] = "abcdefg";
	char a3[10] = { 0 };
	my_memmove(a1 + 2, a1, 3);
	my_memmove(a3, a1, 3);
	printf("�ڴ渲�ǣ�%s\n", a1 + 2);
	printf("������%s\n", a3);
	return 0;
}
*/

//ģʽƥ��
// char *strstr(const char* str1, const char* str2);


//���ش�����,����Ӧ�Ĵ�����Ϣ
//����ͷ�ļ�  #include <error.h>
//char *strerror(int errnum);



/*
//�Ƚ�ascii��С
int my_strcmp(char *str1, const char *str2)
{
	assert(str1 != NULL && str2!= NULL);
	char *p1= str1;
	char *p2 = str2;
	int ret = 0;
	while (*p1!='\0' || *p2!='\0')
	{
		if (*p1 - *p2 != 0)
			break;
		*p1++;
		*p2++;
	}
	ret = *p1 - *p2;
	return ret;
}


int main()
{
	char *a = "hi ";
	char *b = "world";
	int temp=my_strcmp(a, b);
	if (temp == 0)
		printf("a == b\n");
	else if (temp > 0)
		printf(" a > b \n");
	else if (temp < 0)
		printf(" a < b \n");

}
*/

/*
char *my_strcat(char *strDes, const char *strSou)
{
	assert(strDes != NULL && strSou != NULL);
	char *pD = strDes;
	char *pS = strSou;
	while (*pD != '\0')   //�ҵ�ĩβ
	{
		*pD++;
	}
	while (*pS != '\0')    //����
	{
		*pD++ = *pS++;
	}
	*pD = '\0';     //���ĩβ\0
	return strDes;
}

int main()
{
	char a[20] = "hello ";
	char *b= "world";
	my_strcat(a, b);
	printf("%s\n", a);
}
*/


/*

char *my_strcpy(char *strDestination, const char *strSource)
{
	assert(strDestination != NULL && strSource != NULL);   //������
	char *pD = strDestination;    //��������
	char *pS = strSource;
	while ( *pS!='\0')
	{
		*pD++= *pS++;
	}
	*pD = '\0';
	return strDestination;
}
int main()
{
	char a[] = "abcd";
	char *b = "123";
	my_strcpy(a, b);
	printf("%s\n",a );
	system("pause");

}
*/

//���õ���������
/*
size_t my_strlen(const char *string)
{
	if (*string == '\0')
		return 0;
	else
		return my_strlen(string+1) + 1;
}
int main()
{
	char *string= "abcdef";
	printf("%d\n", my_strlen(string));
	system("pause");
}
*/

/*
	��ָ��ʱ�����ж��Ƿ�ΪNULL���ٶ�ָ����в�������
	assert��string !=NULL)
	const char *p_str=string;
*/


//    \0 == 0    \0 != '0'   
//    "\"ת��  ����>   int 5 = char '\5'   

/*
int main()
{
	char str[] = "  ";
	printf("%d\n", strlen(str));   //�ַ���ĩβ��\0
	system("pause");
}
*/
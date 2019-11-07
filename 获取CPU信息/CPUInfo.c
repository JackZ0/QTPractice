#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define HWI_BUFFER_SIZE 512

#define cpuid(func,eax,ebx,ecx,edx)\
	__asm__ __volatile__ ("cpuid":\
	"=a" (eax),"=b" (ebx),"=c" (ecx),"=d" (edx):\
	"a" (func));	

typedef struct _CPU_INFO
{
	char Company[256];
	char BaseParam[256];
	char SerialNumber[256];
	char Brand[512];
	char md5_hash[40];//128bit
} CPU_INFO,*PCPU_INFO;

void getCPUID(char *cpuId)
{
	int a,b,c,d;
	char cpuid_buf[HWI_BUFFER_SIZE];

	memset((void*)cpuid_buf,0,HWI_BUFFER_SIZE);
	cpuid(0x80000004,a,b,c,d);
	sprintf(cpuid_buf,"%#010x %#010x %#010x %#010x",a,b,c,d);
	strcpy(cpuId,cpuid_buf);
}

void getCPUBrand(char *cBrand)
{

	int a,b,c,d,i;
	unsigned int cpu_brand_buf[13];
	int k = 0;

	
	memset((void*)cpu_brand_buf,0,sizeof(cpu_brand_buf));
	/**
     * eax == 0x800000000
     * 如果CPU支持Brand String，则在EAX中返 >= 0x80000004的值。
     */
	cpuid(0x80000000,a,b,c,d);
	if(a < 0x80000004)
	{
		printf("the cpu is not support\n");
		return;
	}

	/**
     * 如果支持Brand String，则EAX从0x80000002到0x80000004，每次增1，CPUID指令返回：
     * EAX    : Processor Brand String
     * EBX    : Processor Brand String Continued
     * ECX    : Processor Brand String Continued
     * EDX    : Processor Brand String Continued
     */
	for(i=0x80000002;i<=0x80000004;i++)
	{
		cpuid(i,a,b,c,d);
		cpu_brand_buf[k++]=a;
		cpu_brand_buf[k++]=b;
		cpu_brand_buf[k++]=c;
		cpu_brand_buf[k++]=d;
		
	}
	strcpy(cBrand,(char*)cpu_brand_buf);
	printf("CPU Brand:%s\n", (char *)cpu_brand_buf);
}


void getCPUCompany(char *cCom)
{
	char ComName[13];
	int a,b,c,d;
	int i,k;

	memset((void*)ComName,0,sizeof(ComName));
	cpuid(0,a,b,c,d);

	for(i = 0; b > 0; i++)
	{
		k = b;
		k = (k>>8);
		k = (k<<8);
		ComName[i]=b-k;
		b=(b>>8);
		
	}
	for(; d > 0; i++)
	{
		k = d;
		k = (k>>8);
		k = (k<<8);
		ComName[i]=d-k;
		d=(d>>8);
		
	}
	for(; c > 0; i++)
	{
		k = c;
		k = (k>>8);
		k = (k<<8);
		ComName[i]=c-k;
		c=(c>>8);
		
	}
	ComName[12]='\0';
	strcpy(cCom,ComName);
	
}

void getCPUBaseParam(char *baseParam)
{
	

	char baseParamBuf[HWI_BUFFER_SIZE];
	unsigned long CPUBaseInfo;
	int a,b,c,d;

	memset((void*)baseParamBuf,0,HWI_BUFFER_SIZE);
	cpuid(1,a,b,c,d);

	CPUBaseInfo = a;
	
	sprintf(baseParamBuf,"Family:%d Model:%d Stepping ID:%d",
		(CPUBaseInfo & 0x0F00)>>8,(CPUBaseInfo & 0xF0)>>4,CPUBaseInfo & 0xF);
	strcpy(baseParam,baseParamBuf);
	
}

void InitCPUStruct(PCPU_INFO CPUStruct)
{
	if(CPUStruct == NULL)
	{
		return;
	}

	memset(CPUStruct,0,sizeof(*CPUStruct));
		
}

void FillCPUStruct(PCPU_INFO cpustruct)
{
	char tmpStr[512];
	char infobuffer[2048];
	char *bufptr = NULL;
	char *md5str = NULL;
	int n = 0;
	
	if(cpustruct == NULL)
		return;
	
	//Initialize infobuffer
	memset(infobuffer, 0, 2048);
	
	//Get CPU Company
	memset(tmpStr, 0, 512);
	getCPUCompany(tmpStr);
	n = strlen(tmpStr);
	strcpy(cpustruct->Company, tmpStr);
	strcpy(infobuffer, tmpStr);
	bufptr = infobuffer + n;
	
	memset(tmpStr, 0, 512);
	getCPUBaseParam(tmpStr);
	n = strlen(tmpStr);
	strcpy(cpustruct->BaseParam, tmpStr);
	strcpy(bufptr, tmpStr);
	bufptr += n;
	
	memset(tmpStr, 0, 512);
	getCPUID(tmpStr);
	n = strlen(tmpStr);
	strcpy(cpustruct->SerialNumber, tmpStr);
	strcpy(bufptr, tmpStr);
	bufptr += n;

	memset(tmpStr, 0, 512);
	getCPUBrand(tmpStr);
	n = strlen(tmpStr);
	strcpy(cpustruct->Brand, tmpStr);
	strcpy(infobuffer, tmpStr);
	bufptr = infobuffer + n;
	
	//Calculate md5 hash
	md5str = (char *)MDString(infobuffer);
	strcpy(cpustruct->md5_hash, md5str);
	
	
}

void print_cpu_info(PCPU_INFO cpustruct)
{
	if(cpustruct == NULL)
		return;
	printf("CPU Information:\n");
	printf("\tCPU Manufacturer: %s\n", cpustruct->Company);
	printf("\tCPU Base Parameters: %s\n", cpustruct->BaseParam);
	printf("\tCPU Serial Number: %s\n", cpustruct->SerialNumber);
	printf("\tCPU Brand Name: %s\n", cpustruct->Brand);
	printf("\tCPU Info hash value: %s\n", cpustruct->md5_hash);
}

int main()
{
	CPU_INFO CPUStruct ;
	
	InitCPUStruct(&CPUStruct);
	FillCPUStruct(&CPUStruct);
	print_cpu_info(&CPUStruct);
	
	
	//free(&CPUStruct);
	
}



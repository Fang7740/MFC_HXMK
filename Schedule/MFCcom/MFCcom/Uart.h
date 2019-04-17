#include<iostream>
#include<TCHAR.H> 
#include<windows.h>


HANDLESerial_open(LPCWSTR, int);
intSerial_read(HANDLE, void*, int);
intSerial_write(HANDLE, constvoid*, int);
voidSerial_close(HANDLE);
voidclear_buf(unsignedchar*, int);

/**
open serial
@param COMx: eg:_T("COM1")
@param BaudRate:
return 0 success ,return Negative is haed err
*/
HANDLESerial_open(LPCWSTRCOMx, intBaudRate)
{
	HANDLEhCom;
	DCBdcb = { 0 };
	hCom = CreateFile(COMx,
		GENERIC_READ | GENERIC_WRITE,
		0,
		0,
		OPEN_EXISTING,
		0,//FILE_FLAG_OVERLAPPED,   //同步方式 或 重叠方式 
		0
	);

	if (hCom == INVALID_HANDLE_VALUE)
	{
		DWORDdwError = GetLastError();
		printf("Sorry, failed to open the serial\n");
		//return -1;
		printf("The program will terminate in 3 seconds\n");
		Sleep(3000);
		exit(0);
	}
	else
		printf("The serial is successfully opened in a Baudrate %d!\n", BaudRate);

	dcb.DCBlength = sizeof(DCB);

	if (!GetCommState(hCom, &dcb))
	{
		DWORDdwError = GetLastError();
		return(HANDLE)(-1);
	}

	dcb.BaudRate = BaudRate;   //波特率 
	dcb.ByteSize = 8;          //位数 
	dcb.Parity = NOPARITY;     //奇偶检验 
	dcb.StopBits = ONESTOPBIT;  //停止位数 

	if (!SetCommState(hCom, &dcb))
	{
		DWORDdwError = GetLastError();
		return(HANDLE)(-1);
	}
	if (!PurgeComm(hCom, PURGE_RXCLEAR))   return(HANDLE)(-1);

	SetupComm(hCom, 1024, 1024);
	returnhCom;;
}



/**
serial read
@param Buf:data buf
@param size:
@return The len of read
*/
intSerial_read(HANDLEhCom, void*OutBuf, intsize)
{
	DWORDcnt = 0;
	ReadFile(hCom, OutBuf, size, &cnt, 0);
	returncnt;

}

/**
serial write
@param Buf:data buf
@param size:bytes of Buf
@return The len of writen
*/
intSerial_write(HANDLEhCom, constvoid*Buf, intsize)
{
	DWORDdw;
	WriteFile(hCom, Buf, size, &dw, NULL);
	returndw;
}

/**
serial close
*/
voidSerial_close(HANDLEhCom)
{
	CloseHandle(hCom);
}

/**
clear buf
*/
voidclear_buf(unsignedchar*buf, intN)
{
	inti;
	for (i = 0; i < N; i++)buf[i] = 0;
	buf[i] = '\0';
}

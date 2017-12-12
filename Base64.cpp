
#include "Base64.h"
#include "WFLibConfig.h"

static const char g_Base64CharTable[] = 
{
	'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N',
	'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
	'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
	'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
	'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '/'
};

static const unsigned int g_uBase64CharTableSize = sizeof(g_Base64CharTable) / sizeof(g_Base64CharTable[0]);

unsigned int CalcBase64EncodeSize(const unsigned int uBufferSize)
{
	unsigned int uEncodeSize = 0;

	if (uBufferSize)
	{
		uEncodeSize = uBufferSize / 3 * 4;

		if (uBufferSize % 3)
		{
			uEncodeSize += 4;
		}
	}

	return uEncodeSize;
}

bool Base64Encode(const unsigned char * pBuffer, const unsigned int uBufferSize, unsigned char * pBufferOut, const unsigned int uBufferOutSize)
{
	bool bRet = false;
	unsigned int uRemaindBytes = 0;
	unsigned char Byte3[3] = { 0 };
	unsigned char Byte4[4] = { 0 };
	unsigned int i = 0;

	if (pBuffer && uBufferSize && pBufferOut && uBufferOutSize)
	{
		for (i = 0; i < uBufferSize / 3; ++i)
		{
			Byte3[0] = pBuffer[i * 3 + 0];
			Byte3[1] = pBuffer[i * 3 + 1];
			Byte3[2] = pBuffer[i * 3 + 2];

			Byte4[0] = (Byte3[0] & 0xFC) >> 2;
			Byte4[1] = ((Byte3[0] & 0x03) << 4) | ((Byte3[1] & 0xF0) >> 4);
			Byte4[2] = ((Byte3[1] & 0x0F) << 2) | ((Byte3[2] & 0xC0) >> 6);
			Byte4[3] = Byte3[2] & 0x3F;

			pBufferOut[i * 4 + 0] = g_Base64CharTable[Byte4[0]];
			pBufferOut[i * 4 + 1] = g_Base64CharTable[Byte4[1]];
			pBufferOut[i * 4 + 2] = g_Base64CharTable[Byte4[2]];
			pBufferOut[i * 4 + 3] = g_Base64CharTable[Byte4[3]];
		}

		uRemaindBytes = uBufferSize % 3;

		if (1 == uRemaindBytes)
		{
			Byte3[0] = pBuffer[i * 3 + 0];

			Byte4[0] = (Byte3[0] & 0xFC) >> 2;
			Byte4[1] = (Byte3[0] & 0x03) << 4;

			pBufferOut[i * 4 + 0] = g_Base64CharTable[Byte4[0]];
			pBufferOut[i * 4 + 1] = g_Base64CharTable[Byte4[1]];
			pBufferOut[i * 4 + 2] = '=';
			pBufferOut[i * 4 + 3] = '=';
		}
		else if (2 == uRemaindBytes)
		{
			Byte3[0] = pBuffer[i * 3 + 0];
			Byte3[1] = pBuffer[i * 3 + 1];

			Byte4[0] = (Byte3[0] & 0xFC) >> 2;
			Byte4[1] = ((Byte3[0] & 0x03) << 4) | ((Byte3[1] & 0xF0) >> 4);
			Byte4[2] = (Byte3[1] & 0x0F) << 2;

			pBufferOut[i * 4 + 0] = g_Base64CharTable[Byte4[0]];
			pBufferOut[i * 4 + 1] = g_Base64CharTable[Byte4[1]];
			pBufferOut[i * 4 + 2] = g_Base64CharTable[Byte4[2]];
			pBufferOut[i * 4 + 3] = '=';
		}

		bRet = true;
	}

	return bRet;
}

#if defined USE_STD_STRING_BASE64

bool StdBase64Encode(const unsigned char * pBuffer, const unsigned int uBufferSize, std::string & strBase64)
{
	bool bRet = false;
	char * pszBase64 = 0;
	unsigned int uBase64Length = 0;

	if (pBuffer && uBufferSize)
	{
		uBase64Length = CalcBase64EncodeSize(uBufferSize);

		if (uBase64Length)
		{
			pszBase64 = new char[uBase64Length + 1];

			if (pszBase64)
			{
				if (Base64Encode((unsigned char *)pBuffer, uBufferSize, (unsigned char *)pszBase64, uBase64Length + 1))
				{
					pszBase64[uBase64Length] = '\0';

					strBase64 = pszBase64;

					bRet = true;
				}

				delete[] pszBase64;
				pszBase64 = 0;
			}
		}
	}

	return bRet;
}

#endif

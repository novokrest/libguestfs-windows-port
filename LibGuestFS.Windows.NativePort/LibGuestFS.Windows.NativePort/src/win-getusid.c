#include <windows.h>
#include <sddl.h>

char*
getusid()
{
    HANDLE hProc;
    HANDLE hToken;
    PTOKEN_USER pUserInfo;
    DWORD dwSize = 0, dwResult;
    char* ret;

    hProc = OpenProcess(PROCESS_QUERY_INFORMATION, FALSE, GetCurrentProcessId());

    if (!OpenProcessToken(GetCurrentProcess(), TOKEN_QUERY, &hToken)) {
        return NULL;
    }

    if (!GetTokenInformation(hToken, TokenUser, NULL, dwSize, &dwSize)) {
        dwResult = GetLastError();
        if (dwResult != ERROR_INSUFFICIENT_BUFFER) {
            return NULL;
        }
    }

    pUserInfo = (PTOKEN_USER)GlobalAlloc(GPTR, dwSize);
    if (!GetTokenInformation(hToken, TokenUser, pUserInfo, dwSize, &dwSize)) {
        if (pUserInfo) {
            GlobalFree(pUserInfo);
        }
        return NULL;
    }

    if (!ConvertSidToStringSid(pUserInfo->User.Sid, &ret)) {
        if (pUserInfo) {
            GlobalFree(pUserInfo);
        }
        return NULL;
    }

    if (pUserInfo) {
        GlobalFree(pUserInfo);
    }

    return ret;

}
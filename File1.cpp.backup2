// KO Integrated Hack DLL - C++ & C# Projeleri Birleştirildi
// File1.cpp - Ana DLL Dosyası

#include <vcl.h>
#include <windows.h>
#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <chrono>
#include <math.h>
#include "Unit1.h"
#include "Pointers.h"

using namespace std;

// Global değişkenler
DWORD KOGelenPaketFonksiyon_PTR = 0xB8F540;
DWORD KOGelenPaketFonksiyon = 0;
bool bRunning = true;
HANDLE hBotThread = NULL;

// Yardımcı fonksiyonlar
__inline DWORD RDWORD(DWORD ulBase)
{
    if (!IsBadReadPtr((VOID*)ulBase, sizeof(DWORD)))
        return(*(DWORD*)(ulBase));
    return 0;
}

__inline float RFLOAT(DWORD ulBase)
{
    if (!IsBadReadPtr((VOID*)ulBase, sizeof(float)))
        return(*(float*)(ulBase));
    return 0.0f;
}

__inline void WRITEDWORD(DWORD ulBase, DWORD value)
{
    if (!IsBadWritePtr((VOID*)ulBase, sizeof(DWORD)))
        *(DWORD*)(ulBase) = value;
}

__inline void WRITEFLOAT(DWORD ulBase, float value)
{
    if (!IsBadWritePtr((VOID*)ulBase, sizeof(float)))
        *(float*)(ulBase) = value;
}

// C# projesinden adapte edilen fonksiyonlar
DWORD KO_GetBase(DWORD ID)
{
    DWORD PBase = 0;
    DWORD GetStatusFunc = 0;
    if ((int)ID > 5000) GetStatusFunc = KO_FMBS;
    else GetStatusFunc = KO_FPBS;
    __asm
    {
        mov ecx, KO_FLDB
        mov ecx, [ecx]
        push 1
        push ID
        mov edi, GetStatusFunc
        call edi
        mov PBase, eax
    }
    return PBase;
}

void KO_LegalAttack(DWORD skillID, DWORD targetID)
{
    __asm
    {
        mov ecx, [KO_PTR_SMMB]
        mov ecx, dword ptr ds:[ecx]
        push skillID
        mov edi, KO_FNC_SMMB
        call edi
        mov ecx, [KO_PTR_DLG]
        mov ecx, dword ptr ds:[ecx]
        mov ecx, [ecx + 0x448]
        push eax
        push targetID
        mov edi, KO_LEGALSKILL
        call edi
    }
}

void KO_SendPacket(BYTE* packet, int length)
{
    DWORD pktPtr = RDWORD(KO_PTR_PKT);
    if (!pktPtr) return;
    __asm
    {
        mov ecx, pktPtr
        mov ecx, dword ptr ds:[ecx]
        push length
        push packet
        mov eax, KO_FNC_SND
        call eax
    }
}

// Bot motoru
void RunBotEngine()
{
    while (bRunning)
    {
        try {
            DWORD playerBase = RDWORD(KO_PTR_CHR);
            if (playerBase)
            {
                float posX = RFLOAT(playerBase + KO_OFF_POSX);
                float posY = RFLOAT(playerBase + KO_OFF_POSY);
                DWORD hp = RDWORD(playerBase + KO_OFF_HP);
                DWORD maxHp = RDWORD(playerBase + KO_OFF_MAX_HP);
                
                static int tick = 0;
                if (tick++ % 100 == 0)
                {
                    cout << "[BOT] Pos: " << posX << ", " << posY 
                         << " | HP: " << hp << "/" << maxHp << endl;
                }
            }
            Sleep(100);
        } catch (...) {
            Sleep(1000);
        }
    }
}

DWORD WINAPI BotThread(LPVOID lpParam)
{
    AllocConsole();
    FILE* f;
    freopen_s(&f, "CONOUT$", "w", stdout);
    cout << "KO Integrated DLL Injected!" << endl;
    RunBotEngine();
    if (f) fclose(f);
    FreeConsole();
    return 0;
}

// DLL giriş noktası
int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void* lpReserved)
{
    switch(reason)
    {
    case DLL_PROCESS_ATTACH:
        DisableThreadLibraryCalls(hinst);
        hBotThread = CreateThread(NULL, 0, BotThread, NULL, 0, NULL);
        break;
    case DLL_THREAD_ATTACH:
        break;
    case DLL_THREAD_DETACH:
        break;
    case DLL_PROCESS_DETACH:
        bRunning = false;
        if (hBotThread) {
            WaitForSingleObject(hBotThread, 5000);
            CloseHandle(hBotThread);
        }
        break;
    }
    return TRUE;
}

// Orijinal fonksiyonlar
int WINAPI GUILOAD()
{
    try {
        Application->Initialize();
        Application->MainFormOnTaskBar = true;
        Application->CreateForm(__classid(TForm1), &Form1);
        Application->Run();
    } catch (...) {}
    return 0;
}

void __stdcall FakeFunction()
{
    *(DWORD*)KOGelenPaketFonksiyon_PTR = (DWORD)KOGelenPaketFonksiyon;
    Form1 = new TForm1(NULL);
    Application->CreateForm(__classid(TForm1), &Form1);
    Form1->Show();
}

__declspec (naked) void ThreadFakeCall()
{
    _asm {
        pushad
        call FakeFunction
        popad
        jmp dword ptr[KOGelenPaketFonksiyon]
    }
}

// Knight Online Güncel Pointer ve Offset Tanımları
// Güncelleme Tarihi: [Güncel]
// Kaynak: Sağlanan güncel pointer ve offset listesi

#ifndef POINTERS_H
#define POINTERS_H

#include <windows.h>

// ============================================================================
// ANA POINTER'LAR (GÜNCEL)
// ============================================================================
#define KO_PTR_CHR 0x010F5FE0
#define KO_PTR_PKT 0x010F60AC
#define KO_FLDB 0x010F5FEC
#define KO_PTR_DLG 0x010F6094
#define KO_FNC_SND 0x00701660
#define KO_FNC_SEL 0x0080D4B0

// ============================================================================
// OFFSET'LER (GÜNCEL)
// ============================================================================
#define KO_OFF_POSX 0x3CC
#define KO_OFF_POSY 0x3D4
#define KO_OFF_POSZ 0x194
#define KO_OFF_ID 0x6A0
#define KO_OFF_NAME 0x6A4
#define KO_OFF_HP 0x6D8
#define KO_OFF_MAX_HP 0x6D4
#define KO_OFF_MP 0xBF0
#define KO_OFF_MAX_MP 0xBEC
#define KO_OFF_CLASS 0x6CC

// ============================================================================
// ESKİ OFFSET'LER (UYUMLULUK İÇİN)
// ============================================================================
#define KO_OFF_X KO_OFF_POSX
#define KO_OFF_Y KO_OFF_POSY
#define KO_OFF_Z KO_OFF_POSZ
#define KO_OFF_HP KO_OFF_HP
#define KO_OFF_MAXHP KO_OFF_MAX_HP
#define KO_OFF_MP KO_OFF_MP
#define KO_OFF_MAXMP KO_OFF_MAX_MP
#define KO_OFF_MOB 0x000006D4
#define KO_OFF_Go1 0x000010C0
#define KO_OFF_GoX 0x000010CC
#define KO_OFF_GoY 0x000010D4
#define KO_OFF_NAMELEN 0x00000730

#endif // POINTERS_H

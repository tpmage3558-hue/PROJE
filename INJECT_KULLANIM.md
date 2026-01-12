# 🎯 hexbot.dll - INJECT KULLANIM KILAVUZU

## 📦 DERLENEN DOSYA
**Konum:** `ICExProject\bin\Release\hexbot.dll`
**Boyut:** ~XXX KB
**Framework:** .NET 4.8
**Hedef:** Knight Online (32-bit/64-bit)

---

## 🚀 INJECT NASIL YAPILIR?

### **Yöntem 1: hexLoader.exe ile** (ÖNERİLEN)

1. **Knight Online'ı başlat** ve oyuna gir
2. **hexLoader.exe**'yi yönetici olarak çalıştır
3. **DLL Seç** butonuna tıkla ve `hexbot.dll`'i seç
4. **Process Seç** -> "KnightOnLine.exe" seçin
5. **Inject** basın!

✅ Console penceresi açılacak:
```
[hexbot.dll] Inject başarılı!
[hexbot.dll] ICEx Bot Engine yükleniyor...
[hexbot.dll] Pointer'lar: GÜNCEL (2025 Ocak)
[hexbot.dll] Thread başlatıldı!
[hexbot.dll] GUI başlatılıyor...
```

✅ Bot GUI penceresi otomatik açılır!

---

### **Yöntem 2: ConsoleLoader.exe ile**

```bash
ConsoleLoader.exe KnightOnLine.exe hexbot.dll
```

---

## ⚙️ İÇERİK KONTROLÜ

DLL inject olurken şunlar çalışır:

### 1. **Initialize() Fonksiyonu**
- ✅ Console aç (debug için)
- ✅ Pointer kontrolü
- ✅ Ana thread başlat

### 2. **MainThread() Fonksiyonu**
- ✅ GUI initialize
- ✅ frm_1Giris formunu aç
- ✅ Bot engine hazırla

### 3. **Bot Özellikleri**
- ✅ **GÜNCEL Pointer'lar** (2025 Ocak 10)
- ✅ **GetBase()** - Optimized mob/player base
- ✅ **LegalAttack()** - XignCode bypass
- ✅ **WidexSource** entegrasyonu
- ✅ **Archer/Asas** attack patterns
- ✅ **Auto loot** sistemi

---

## 🛠️ GELİŞMİŞ AYARLAR

### **Pointer Güncelleme**
Eğer oyun güncellenirse, `cls_Bot.cs` içindeki pointer'ları değiştir:

```csharp
// GÜNCEL POINTER'LAR (2025 Ocak 10)
public const int KO_PTR_CHR = 0x010F5FE0;   // Karakter
public const int KO_PTR_DLG = 0x010F6094;   // Dialog
public const int KO_PTR_PKT = 0x010F60AC;   // Paket
public const int KO_SND_FNC = 0x00701660;   // Send
public const int KO_FLDB = 0x010F5FEC;      // Field DB
```

Değiştirdikten sonra:
```bash
MSBuild ICExProject.sln /t:Rebuild /p:Configuration=Release
```

---

## 🔒 GÜVENLİK İPUÇLARI

### ✅ YAPILMASI GEREKENLER:
1. **Anti-virus'ü kapat** - False positive olabilir
2. **Yönetici olarak çalıştır** - Loader'ı admin yetkisiyle aç
3. **Oyunu windowed modda** - Full screen crash yapabilir
4. **Test karakteri kullan** - İlk testlerde main char kullanma

### ⚠️ YAPILMAMASI GEREKENLER:
1. **GM yanında kullanma** - Tespit riski!
2. **Hızlı hareket ettirme** - Speed hack = ban
3. **Çok fazla loot toplama** - Şüphe çeker
4. **Aynı anda 10+ skill** - Pattern tespiti

---

## 🐛 SORUN GİDERME

### **"DLL inject edilemedi"**
➡️ Loader'ı **yönetici olarak** çalıştır
➡️ Anti-virus'ü kapat
➡️ Knight Online 32-bit mi kontrol et

### **"Console açılıyor ama GUI yok"**
➡️ `frm_1Giris.cs` form dosyası eksik olabilir
➡️ DllMain.cs'teki `Application.Run()` satırını kontrol et

### **"Pointer hataları"**
➡️ Oyun güncellenmiş olabilir
➡️ `cls_Bot.cs` içindeki pointer'ları güncelle
➡️ Pattern scanner kullan (PointerScanner.cs)

### **"XignCode crash"**
➡️ `KO_LEGALSKILL` değerini kontrol et
➡️ `LegalAttack()` basit versiyonunu kullan:
```csharp
// DllMain.cs içine ekle:
public const bool USE_SIMPLE_ATTACK = true;
```

---

## 📊 PERFORMANS

| Özellik | Durum | Açıklama |
|---------|-------|----------|
| Memory Read | ✅ Optimized | Unsafe pointer kullanımı |
| Packet Send | ✅ Fast | Direct ASM call |
| GetBase() | ✅ 5000 eşiği | C++ SnoxdTr algoritması |
| LegalAttack | ✅ Bypass | XignCode3 safe |
| Skill System | ✅ Full | Tüm sınıflar destekli |

---

## 📞 DESTEK

**Hata raporları için:**
- Console çıktısını kaydet
- Oyun versiyonunu belirt
- Kullanılan loader'ı belirt

**Başarılı inject mesajı:**
```
[hexbot.dll] Inject başarılı!
[hexbot.dll] ICEx Bot Engine yükleniyor...
[hexbot.dll] Pointer'lar: GÜNCEL (2025 Ocak)
[hexbot.dll] Thread başlatıldı!
[hexbot.dll] GUI başlatılıyor...
```

Bu mesajları görürseniz her şey TAMAM! 🎉

---

## 💾 YEDEKLESağladığınız hexLoader.exe gibi farklı injectorlar da test edebilirsiniz.

**NOT:** DLL her inject'te yeni instance oluşturur. Oyunu kapatıp açmanız gerekir.

// هذا الكود مصمم ليتم إضافته داخل مشروع Bruce الخاص بك (مثلاً في ملف wifi_atks.cpp أو أي ملف يدير فحص الشبكة)

#include <WiFi.h>
#include <HTTPClient.h>

// ضع هنا عنوان السيرفر الذي قمنا بإنشائه للتو (يجب أن يكون جهازك والـ ESP32 على نفس الشبكة)
// استبدل YOUR_BACKEND_IP بـ الآيبي الداخلي لجهاز الكمبيوتر الخاص بك
const char* serverUrl = "http://YOUR_BACKEND_IP:3001/api/ingest";

void sendDataToMWFA(String targetMac, String targetIp, String netSsid, String netBssid) {
    // التأكد من أن الـ ESP32 متصل بالشبكة التي يتواجد عليها الخادم
    if (WiFi.status() == WL_CONNECTED) {
        HTTPClient http;
        http.begin(serverUrl);
        http.addHeader("Content-Type", "application/json");

        // تجهيز البيانات بصيغة JSON
        String jsonPayload = "{";
        jsonPayload += "\"macAddress\":\"" + targetMac + "\",";
        jsonPayload += "\"ipAddress\":\"" + targetIp + "\",";
        jsonPayload += "\"ssid\":\"" + netSsid + "\",";
        jsonPayload += "\"bssid\":\"" + netBssid + "\"";
        jsonPayload += "}";

        // إرسال البيانات
        int httpResponseCode = http.POST(jsonPayload);
        
        if (httpResponseCode > 0) {
            Serial.print("[+] Data sent to MWFA successfully. Response: ");
            Serial.println(httpResponseCode);
        } else {
            Serial.print("[-] Error sending data to MWFA: ");
            Serial.println(httpResponseCode);
        }
        
        http.end();
    } else {
        Serial.println("[-] WiFi not connected. Cannot send data to MWFA.");
    }
}

// مثال على كيفية استدعاء الدالة عند إيجاد جهاز جديد أثناء فحص الشبكة (Scanning):
// sendDataToMWFA("00:11:22:33:44:55", "192.168.1.15", "MyHomeWiFi", "AA:BB:CC:DD:EE:FF");

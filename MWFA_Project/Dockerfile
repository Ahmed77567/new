# 1. الصورة الأساسية اللي بيها أدوات كالي
FROM cyberillo/kali-mcp-server:latest

# 2. تثبيت بيئة Node.js داخل الكالي
RUN apt-get update && apt-get install -y curl
RUN curl -fsSL https://deb.nodesource.com/setup_18.x | bash -
RUN apt-get install -y nodejs

# 3. تحديد مجلد العمل داخل الحاوية
WORKDIR /app

# 4. ننسخ كل محتويات مجلد الباكند مباشرة لداخل الحاوية
COPY backend/ ./

# 5. التثبيت المرن
RUN npm install

# 6. فتح بورت الباكند
EXPOSE 3000

# 7. تشغيل الباكند
CMD ["node", "server.js"]
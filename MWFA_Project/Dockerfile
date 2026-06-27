# 1. الصورة الأساسية اللي بيها أدوات كالي
FROM cyberillo/kali-mcp-server:latest

# 2. تثبيت بيئة Node.js داخل الكالي
RUN apt-get update && apt-get install -y curl
RUN curl -fsSL https://deb.nodesource.com/setup_18.x | bash -
RUN apt-get install -y nodejs

# 3. تحديد مجلد العمل داخل الحاوية
WORKDIR /app

# 4. نسخ ملفات التعريف من نفس المجلد
COPY package*.json ./

# 5. التثبيت المرن
RUN npm install

# 6. نسخ باقي كود الباكند (mcpService.js, server.js)
COPY . .

# 7. فتح بورت الباكند
EXPOSE 3000

# 8. تشغيل الباكند مالتك
CMD ["node", "server.js"]

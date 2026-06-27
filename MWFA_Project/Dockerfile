################################################################
# MWFA Backend — Dockerfile
# Multi-stage build: Builder → Production
################################################################

# ── Stage 1: Builder ─────────────────────────────────────────
FROM node:20-alpine AS builder

WORKDIR /app

# نسخ ملفات الـ dependencies أولاً (لتسريع الـ cache)
COPY backend/package*.json ./
RUN npm ci --only=production

# نسخ كامل الـ source
COPY backend/ .

# توليد Prisma Client
RUN npx prisma generate

# ── Stage 2: Production ──────────────────────────────────────
FROM node:20-alpine AS production

WORKDIR /app

# نسخ من الـ builder
COPY --from=builder /app/node_modules ./node_modules
COPY --from=builder /app .

# تشغيل الـ migrations ثم الـ server
CMD ["sh", "-c", "npx prisma db push --skip-generate && node server.js"]

EXPOSE 3001

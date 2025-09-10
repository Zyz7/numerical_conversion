FROM gcc:latest

WORKDIR /app

COPY . .

RUN gcc -o main main.c -lm

CMD ["./main"]

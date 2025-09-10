FROM gcc:lastest

WORKDIR /app

COPY . .

RUN gcc -o main main.c -lm

CMD ["./main"]

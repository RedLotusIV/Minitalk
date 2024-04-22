# Minitalk
### client sending to server by translating each character to a bit then to a singal (example):
'c' = 01100011 | 1 = 00000001
'c' = 00000001 = 1, SIGUSR1
'c' = 00000010 = 1, SIGUSR1
'c' = 00000000 = 0, SIGUSR2
'c' = 00000000 = 0, SIGUSR2
'c' = 00000000 = 0, SIGUSR2
'c' = 00100000 = 1, SIGUSR1
'c' = 01000000 = 1, SIGUSR1
'c' = 00000000 = 0, SIGUSR2
sleep 100 microseconds to give enough time to send the signal
kill is a function that sends a signal to a pid you give
### then the server translate the user defined signals to 0s and 1s and combine them in a character then write it (example):
SIGUSR1, i = 00000000 | 00000001 = 00000001, bits = 0
SIGUSR1, i = 00000001 | 00000010 = 00000011, bits = 1
SIGUSR2, i = 00000011, bits = 2
SIGUSR2, i = 00000011, bits = 3
SIGUSR2, i = 00000011, bits = 4
SIGUSR1, i = 00000011 | 00100000 = 00100011, bits = 5
SIGUSR1, i = 00100011 | 01000000 = 01100011, bits = 6
SIGUSR2, i = 01100011, bits = 7
bits++;
then print the i as character from the built binary, reset the static then continue

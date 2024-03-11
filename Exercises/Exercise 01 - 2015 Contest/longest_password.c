/*
Task: https://app.codility.com/programmers/trainings/1/longest_password/
Score: https://app.codility.com/demo/results/trainingFQYHJC-XSW/

Algorithm:
1. The outer loop runs until it encounters the end of text character.
2. The inner loop continues until it encounters a space character or the end of the text.
3. After scanning each letter/digit in individual words occurring between spaces, the parity/odd 
condition for the letters/digits is checked according to the task command and the current counters are 
reset to zero.
4. If an illegal character occurs while scanning a word, the word is moved to the next word and the 
current counter is reset.
5. The longest word that meets all the conditions of the task is remembered from the current counter.
6. An interesting property of the XOR operator (^) is used to switch between even / odd (0 / 1).
*/

int solution(char *S)
{
    int i = 0, letters = 0, digits = 0, counter = 0, result = 0;

    do
    {
        while (S[i] != ' ' && S[i] != '\0')
        {
            if ((S[i] >= 'a' && S[i] <= 'z') || (S[i] >= 'A' && S[i] <= 'Z'))
            {
                counter++;
                letters ^= 1;
            }
            else if (S[i] >= '0' && S[i] <= '9')
            {
                counter++;
                digits ^= 1;
            }
            else
            {
                while (S[i] != ' ' && S[i] != '\0')
                    i++;
                counter = 0;
                break;
            }
            i++;
        }

        if (letters == 0 && digits == 1)
            result = counter > result ? counter : result;

        letters = digits = counter = 0;
        i++;

    } while (S[i] != '\0');

    if (result == 0)
        return -1;
    else
        return result;
}

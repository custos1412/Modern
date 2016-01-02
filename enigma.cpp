#include <stdio.h>
#include <string.h>
//////////////////// a    b    c    d    e    f    g    h    i    j    k    l    m    n    o    p    q    r    s    t    u    v    w    x    y    z
char wheel0[26] = { 'I', 'R', 'C', 'L', 'H', 'F', 'P', 'J', 'K', 'T', 'M', 'N', 'B', 'E', 'Q', 'V', 'Y', 'D', 'G', 'W', 'S', 'A', 'U', 'O', 'Z', 'X' };
char wheel1[26] = { 'W', 'A', 'S', 'U', 'H', 'E', 'P', 'M', 'V', 'G', 'F', 'N', 'J', 'C', 'R', 'K', 'I', 'D', 'Y', 'X', 'T', 'Z', 'B', 'Q', 'L', 'O' };
char wheel2[26] = { 'F', 'R', 'A', 'J', 'S', 'G', 'X', 'Y', 'W', 'U', 'B', 'M', 'C', 'V', 'E', 'P', 'N', 'H', 'K', 'L', 'D', 'Q', 'I', 'O', 'T', 'Z' };
char reflector[26] = { 'S', 'M', 'H', 'G', 'N', 'U', 'D', 'C', 'Z', 'R', 'Y', 'O', 'B', 'E', 'L', 'X', 'W', 'J', 'A', 'V', 'F', 'T', 'Q', 'P', 'K', 'I' };

char daykey[5], msgkey[5], msgkey1[5] = { 'X', 'X', 'F' }, msgkey2[5] = { 'D', 'N', 'H' }, tempkey1[5], tempkey2[5];

char massage[2000] = "GWITTIUINVMJDVZLSPMALXZCUAMGBWNHNREOAZRORDKGNFAUVARQNCBQSTJVJKCZOKAKUEMKIMCDXQIJRXIHRHDXARFFACDLGVIKNKTDVJLYIGFHJTCDPLQERIMKNFZGMQQJYJVHLOYTASFUFEDAMRLXDICKLQPYZKZBONTRTXCRRAVYHCNUZXJKUTVHNTMHCSFKEAQTIAMNJAFSERBHVHDXNQFOTKAKFNRKLXRQCQZIQCVHRHHCCZELNHDKVQPXBDBYVSAWPRAWMSMAIGSEVNSYBFBYZQJGQTTLZQHHXAOKAKUEMBPDKTCQMMBSUWLINCWZPIJDANXPODNWFJQHDBMKKOJCWXSTAFFLGQBCTDUYCSFHBGKKNOCDETQPXRELEYECEYUIFIZTDKRHWPELNRONCKOGTGHQIJLWRMPIOPAOJFNGUCEGMDCAAYLHBDCQKWZZASTYEWONCTPHUDJDLMXJNQGWPVWREEMZYLKZHDRTTGQAFY";

bool msg = false;
int wheel0_s, wheel1_s, wheel2_s;

void start(char* a)
{
	wheel0_s = a[0] - 'A';
	wheel1_s = a[1] - 'A';
	wheel2_s = a[2] - 'A';

	return;
}

void end() //한 개의 문자를 암호화 하고 난 뒤 로터가 한칸 회전한다.
{
	wheel0_s++;
	wheel1_s++;
	wheel2_s++;

	if (wheel0_s > 25)
	{
		wheel0_s = 0;
	}
	if (wheel1_s > 25)
	{
		wheel1_s = 0;
	}if (wheel2_s > 25)
	{
		wheel2_s = 0;
	}

	return;
}


char W(char key)//에니그마의 동작원리를 나타낸다.
{
	key = wheel0[(26 - wheel0_s + key - 'A') % 26];
	key = wheel1[(26 - wheel1_s + key - 'A') % 26];
	key = wheel2[(26 - wheel2_s + key - 'A') % 26];
	key = reflector[key-'A'];

	for (int i = 0; i < 26; i++)
	{
		if (key == wheel2[i])
		{
			key = (i + wheel2_s) % 26+'A';
			break;
		}
	}
	for (int i = 0; i < 26; i++)
	{
		if (key == wheel1[i])
		{
			key = (i + wheel1_s) % 26+'A';
			break;
		}
	}
	for (int i = 0; i < 26; i++)
	{
		if (key == wheel0[i])
		{
			key = (i + wheel0_s) % 26+'A';
			break;
		}
	}
	end();

	return key;
}

void findMK(void)
{
	int i;

	start(daykey);
	for (i = 0; i < 3; i++)
	{
		tempkey1[i] = W(msgkey1[i]);
	}

	for (i = 0; i < 3; i++)
	{
		tempkey2[i] = W(msgkey2[i]);
	}

	for (i = 0; i < 3; i++)
	{
		if (tempkey1[i] != tempkey2[i])
		{
			return;
		}
	}

	msg = true;

	return;
}

void MSG()
{
	start(msgkey);

	for (int i = 0; i < strlen(massage); i++)
	{
		printf("%c", W(massage[i]));
	}

	return;
}

void DK(int k) // MsgKey를 찾고 메시지를 복호화 한다.
{
	if (k == 3)
	{
		findMK();
		if (msg == true)
		{
			for (int i = 0; i < 3; i++)
			{
				msgkey[i] = tempkey1[i];
				printf("%c", msgkey[i]);
			}
			printf("\n");

			MSG();

			printf("\n");

			msg = false;
			return;
		}
		return;
	}

	for (char i = 'A'; i <= 'Z'; i++)
	{
		daykey[k] = i;
		DK(k + 1);
	}

	return;
}

int main(void)
{
	DK(0);

	return 0;
}

/*
AUG
	DURINGWORLDWARIITHEGERMANSCREATEDTHEENIGMAACOMPLICATEDENCRYPTIONMACHINETOKEEPTHE
	IRMESSAGESSECRETFROMTHEIRENEMIESTHOUGHTTOBETHEMOSTSECURECIPHERSYSTEMEVERBUILTTHE
	ENIGMAUSEDACOMBINATIONOFWIREDROTORSANDPLUGSTOCHANGEORENCRYPTEACHLETTERASITWASPRE
	SSEDONTHEKEYBOARDEVERYDAYTHEORDEROFTHEWIREDROTORSINSIDETHEMACHINEWASSWITCHEDACCO
	RDINGTOAKEYLISTTHUSMAKINGITDIFFICULTFORANENEMYTOFIGUREOUTITSCOMPLICATEPATTERNUNT
	ILTHECREATIONOFTHENAVYBOMBETHEENIGMASSECRETMESSAGESWEREUNBREAKABLEWITHOUTAKEYLIS
	TFROMTHENSAWEBSITE
*/

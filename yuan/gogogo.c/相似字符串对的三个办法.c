//int similarPairs(char** words, int wordsSize)
//{
//	int count = 0;
//	int num = 0;
//	char a[wordsSize][27];
//	int len = 0;
//	int flag = 1;
//	int b[wordsSize];
//	for (int i = 0; i < wordsSize; i++)
//	{
//		b[i] = 0;
//		memset(a[i], 0, 27);
//	}
//	for (int i = 0; i < wordsSize; i++)
//	{
//		count = 0;
//		len = strlen(words[i]);
//		for (int j = 0; j < len; j++)
//		{
//			flag = 1;
//			for (int k = 0; k < b[i]; k++)
//			{
//				if (a[i][k] == words[i][j])
//				{
//					flag = 0;
//				}
//			}
//			if (flag)
//			{
//				a[i][count] = words[i][j];
//				b[i]++;
//				count++;
//			}
//		}
//		a[i][b[i]] = '\0';
//	}
//	int abc;
//	for (int i = 0; i < wordsSize; i++)
//	{
//		for (int j = 0; j < b[i] - 1; j++)
//		{
//			for (int k = 0; k < b[i] - j - 1; k++)
//			{
//				if (a[i][k] > a[i][k + 1])
//				{
//					char temp = a[i][k];
//					a[i][k] = a[i][k + 1];
//					a[i][k + 1] = temp;
//				}
//			}
//		}
//	}
//	for (int i = 0; i < wordsSize; i++)
//	{
//		for (int j = i + 1; j < wordsSize; j++)
//		{
//			if (strcmp(a[i], a[j]) == 0)
//			{
//				num++;
//			}
//		}
//	}
//	return num;
//}
//
//版本二
//
//int similarPairs(char** words, int wordsSize)
//{
//	int num = 0;
//	char sortedSets[wordsSize][27];  // 存储每个字符串排序后的字符集合
//
//	for (int i = 0; i < wordsSize; i++) {
//		// 标记字符出现
//		int charExists[26] = { 0 };
//		int len = strlen(words[i]);
//
//		// 标记出现的字符
//		for (int j = 0; j < len; j++) {
//			if (words[i][j] >= 'a' && words[i][j] <= 'z') {
//				charExists[words[i][j] - 'a'] = 1;
//			}
//		}
//
//		// 构建排序后的字符集合
//		int pos = 0;
//		for (int j = 0; j < 26; j++) {
//			if (charExists[j]) {
//				sortedSets[i][pos++] = 'a' + j;
//			}
//		}
//		sortedSets[i][pos] = '\0';  // 字符串结束符
//	}
//
//	// 比较所有字符串对
//	for (int i = 0; i < wordsSize; i++) {
//		for (int j = i + 1; j < wordsSize; j++) {
//			if (strcmp(sortedSets[i], sortedSets[j]) == 0) {
//				num++;
//			}
//		}
//	}
//
//	return num;
//}
//  掩码与位运算
//int similarPairs(char** words, int wordsSize) {
//	int num = 0;
//	int masks[wordsSize];
//
//	for (int i = 0; i < wordsSize; i++) {
//		masks[i] = 0;
//		for (int j = 0; words[i][j]; j++) {
//			masks[i] |= (1 << (words[i][j] - 'a'));
//		}
//	}
//
//	for (int i = 0; i < wordsSize; i++) {
//		for (int j = i + 1; j < wordsSize; j++) {
//			if (masks[i] == masks[j]) {
//				num++;
//			}
//		}
//	}
//	return num;
//}

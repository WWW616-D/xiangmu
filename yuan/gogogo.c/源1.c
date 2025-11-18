/*作业一
	char namai[100] = "没有捏";   括号内为内存占用大小.
	printf("我亲亲女朋友的名字为：%s\n", namai);
	int suishu;
	printf("请输入你的年龄：");
	scanf("%d", &suishu);
	printf("我的年龄是：%d\n", suishu);*/

	/*作业二
	printf("请输入一个三位数：");
	int san;
	scanf("%d", &san);
	int bai = san / 100;
	san = san % 100;
	int shi = san / 10;
	san = san % 10;
	printf("这个三位数的百十个位数分别为%d %d %d", bai, shi, san);*/

	/*test
	float chang;
	float kuan;
	float gao;
	printf("请输入三个小数分别表示长宽高：");
	scanf("%f %f %f", &chang, &kuan, &gao);
	printf("该长方体的表面积为:%.2f",(chang*kuan+chang*gao+kuan*gao)*2);
	float tiji = chang * kuan * gao;
	printf("该长方体的体积为：%.2f", tiji);*/

	/*题目
	int num1;
	int num2;
	printf("请输入两个两位整数：\n" );
	scanf("%d\n%d", &num1, &num2);
	int num3 = num1 % 10;
	int num4 = num2 % 10;
	int num5 = num2 % 7;
	printf("num1为%d\nnum2为%d\n", num1, num2);
	num1 /= 10;
	num2 /= 10;
	printf("对于num1是否带7的判定结果为：%d\n", num3 != 7 && num1 != 7);
	printf("对于num2是否带7且非7的倍数的判定结果为：%d\n", num3 != 7 && num1 != 7 && num5 != 0);*/

	//题目
	/*int paia = 5;
	int paib = 5;
	int shua = 6;
	int shub = 8;
	if (paia = paib && (shua - shub == 1 || shua - shub == -1))
		printf("太棒了");
	else
		printf("那很坏了");*/

		//题目
		/*int fenshu;
		printf("请输入你本次考试的分数：\n");
		scanf("%d", &fenshu);
		if (fenshu >= 95 && fenshu <= 100)
			printf("666");
		else if (fenshu >= 90 && fenshu <= 94)
		{
			printf("可以啊兄弟");
		}
		else if (fenshu >= 85 && fenshu <= 89)
		{
			printf("还行吧");
		}
		else if (fenshu >= 0 && fenshu <= 84)
		{
			printf("还得练老弟");
		}
		else
			printf("不儿哥们别搞啊");*/

			/*switch练习
			int week;
			printf("请输入今天是周几：\n");
			scanf("%d", &week);
			switch (week)//字符或者整数
			//如果没有break case语句将穿透下去
			{
			case 1://字符或者整数，不能是变量
				printf("run\n");
				break;
			case 2:
				printf("swim\n");
				break;
			case 3:
				printf("slow walk\n");
				break;
			case 4:
				printf("I don't know");
				break;
			case 5:
				printf("fight");
				break;
			case 6:
				printf("panpa");
				break;
			case 7:
				printf("eat a big");
				break;
			default:
				printf("别搞哥们\n");
				break;
			}*/

			/*打印数字练习
			int i;
			int he = 0;
			for ( i = 1; i <= 50; i++)
			{
				printf("%d", i);
				he += i;
			}
			printf("%d", he);
			int ouhe = 0;
			for (int ou = 0; ou <= 100; ou += 2)
				ouhe += ou;
			printf("%d", ouhe);*/

			/*
			int zuo;
			int you;
			int jige = 0;
			printf("请输入一个范围：\n");
			scanf("%d %d", &zuo, &you);
			for (int liuba = zuo; liuba <= you; liuba++)
			{
				if (liuba % 6 == 0 && liuba % 8 == 0)
				{
					printf("%d\n", liuba);
					jige++;
				}
			}
			printf("这个范围内liuba有%d个\n", jige);*/

			/*循环算法题
			int i;
			int tong = 0;
			int c;
			printf("请输入一个整数");
			scanf("%d", &i);
			while (i > 2)
			{
				int c = i % 2;
				tong += c;
				i = i / 2;
			}
			if (tong == 0)
				printf("i是2的指数倍");
			else {
				printf("i不是2的指数倍");
			}*/
			/*int zhu = 1;
			int shu = 0;
			while (zhu <= 8844430)
			{
				zhu *= 2;
				shu += 1;
			}
			printf("折叠次数为%d", shu);*/


			/*printf("请输入一个正整数\n");
			int zhengshu;
			scanf("%d", &zhengshu);
			int i = 1;
			while (i * i <= zhengshu)
			{
				i++;
			}
			printf("这个整数的算数平方根为：%d", i - 1);

			int duibi = zhengshu;
			int jie = 0;
			while (zhengshu > 0)
			{
				int shu = zhengshu % 10;
				zhengshu /= 10;
				jie = jie * 10 + shu;
			}
			if (jie == duibi)
				printf("是回文数%d", jie);
			else
			{
				printf("不是回文数%d", jie);
			}*/

			/*for (int i = 1; i <= 3; i++);
			{
				for (int j = 1; j <= 5; j++)
				{
					printf("*");
				}
				printf("\n");
			}*/
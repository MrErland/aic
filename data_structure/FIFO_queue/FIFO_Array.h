/***************Queue by Array****************/
#ifndef _queue_by_array_
#define _queue_by_array_

#define Item int

static Item *q;
static int N, headArray, tailArray;

void InitQue(int Max)	//设置同时存在的最多数目Max
{
	N = Max + 1;
		q = new Item[N]();
			headArray = N;		//head从N开始，回卷后重合
				tailArray = 0;		//tail从0开始
				}

				bool EmptyQue()
				{
					return headArray%N == tailArray;
					}

					void PutQue(Item item)
					{
						q[tailArray++] = item;
							tailArray = tailArray%N;
							}

							Item GetQue()
							{
								headArray = headArray%N;
									return q[headArray++];
									}

									#endif

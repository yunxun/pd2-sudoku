#include <cstdio>
#include <cstring>
#include <cstdlib>

int map[50][50];
bool p[50][50];
bool find=false;
bool flag = false;
bool check(int x,int y ,int z){
	    int xx = x;
		    int yy = y;
				    if(!map[xx][yy])return 0;
			    for(int i = 0 ;i < z*z ;i++)
					        if((map[xx][i] == map[xx][yy] && i != yy)||
										 (map[i][yy] == map[xx][yy] && i != xx))return 0;
				    for(int j = z*(xx/z) ;j < z*(xx/z)+z ;j++)
						        for(int k = z*(yy/z);k < z*(yy/z)+z ;k++)
									            if(map[xx][yy] == map[j][k] && (xx!=j||yy!=k))return 0;
					    return 1;
}

void dfs(int now ,int x ,int xx){
	    if(now>=x*x){
			        find = true;
					        return ;
							    }
		    
		int x_ =now/x, y_ = now%x;
		    for(;map[x_][y_] <= x;map[x_][y_]++){
					for(int i = 0 ;i < 9 ;i ++){
									for(int j = 0 ;j < 9 ;j ++){
														printf("%d ", map[i][j]);
																	}	
												printf("\n");
														}
							getchar();
									system("clear");

									        if(check(x_ ,y_ ,xx)){
												            int nn = now+1;
															            while(p[nn/x][nn%x])nn++;
																		            dfs(nn ,x ,xx);
																					            if(find)return;
																								        }
											    }
			    map[x_][y_] = 0;
				    return;
}

int main(){
	    int n;
		    bool blank = false;
			    while(scanf("%d",&n) != EOF){
					        if(blank)printf("\n");
							        blank = true;
									        if(n==1){
												            int t;
															            scanf("%d" ,&t);
																		            if(t == 1 || !t)printf("1\n");
																					            else printf("NO SOLUTION\n");
																								            continue;
																											        }
											        for(int i = 0; i < 50 ;i++)
												{
for(int j = 0;j < 50;j++){
	                map[i][j] = 0;
					                p[i][j] = 0;
									            }
        }
													        find = false;
															        flag = true;
																	        for(int i = 0; i < n*n ;i++){

 for(int j = 0;j < n*n;j++){
	                 scanf("%d",&map[i][j]);
					                 if(map[i][j]) {
										                     p[i][j] = true;
															                     if(!check(i ,j ,n))flag = false;
																				                 }
									             }
         }
																			        if(flag)dfs(0 ,n*n ,n);
																					        if(!find || !flag){
																								            printf("NO SOlUTION\n");
																											            continue;
																														        }
																							        for(int i = 0 ;i < n*n ;i++){

																										 for(int j = 0 ;j < n*n ;j++){
																											                 if(j)printf(" ");
																															                 printf("%d",map[i][j]);
																																			             }
																										            printf("\n");
																													       }
																									    }
				    return 0;
}


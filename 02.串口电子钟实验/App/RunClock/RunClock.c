/*********************************************************************************************************
* 模块名称：RunClock.c
* 摘    要：RunClock模块
* 当前版本：1.0.0
* 作    者：SZLY(COPYRIGHT 2018 - 2020 SZLY. All rights reserved.)
* 完成日期：2020年01月01日 
* 内    容：
* 注    意：none                                                                  
**********************************************************************************************************
* 取代版本：
* 作    者：
* 完成日期：
* 修改内容：
* 修改文件：
*********************************************************************************************************/

/*********************************************************************************************************
*                                              包含头文件
*********************************************************************************************************/
#include "RunClock.h"
#include <stdio.h>

/*********************************************************************************************************
*                                              宏定义
*********************************************************************************************************/

/*********************************************************************************************************
*                                              内部变量
*********************************************************************************************************/
static  i16 s_iHour;
static  i16 s_iMin ;
static  i16 s_iSec ;
static  i16 s_iYear;
static  i8 s_iMonth;
static  i8 s_iDay ;
static  i8 s_iWeek ;
static  u8  s_iClockPauseFlag = 0;  //TRUE-暂停，FALSE-正常运行
 
/*********************************************************************************************************
*                                              内部函数声明
*********************************************************************************************************/

/*********************************************************************************************************
*                                              内部函数实现
*********************************************************************************************************/
/*********************************************************************************************************
*                                              API函数实现
*********************************************************************************************************/
/*********************************************************************************************************
* 函数名称：InitRunClock
* 函数功能：初始化RunClock模块 
* 输入参数：void
* 输出参数：void
* 返 回 值：void
* 创建日期：2018年01月01日
* 注    意：
*********************************************************************************************************/
void  InitRunClock(void)
{
  s_iHour = 0;
  s_iMin  = 0;
  s_iSec  = 0;
  s_iDay = 1;
  s_iWeek = 1;
  s_iYear = 2018;
  s_iMonth = 1;
}

/*********************************************************************************************************
* 函数名称：RunClockPer2Ms
* 函数功能：计数模块，每2ms调用一次 
* 输入参数：void
* 输出参数：void
* 返 回 值：void
* 创建日期：2018年01月01日
* 注    意：
*********************************************************************************************************/
//void  RunClockPer2Ms(void)
//{
//  static i16 s_iCnt500 = 0;
//
//  if(499 <= s_iCnt500 && 0 == s_iClockPauseFlag)
//  {
//    if(59 <= s_iSec)
//    {
//      if(59 <= s_iMin)
//      {
//        if(23 <= s_iHour)
//        {
//          s_iHour = 0;
//        }
//        else
//        {
//          s_iHour++;
//        }
//        s_iMin = 0;
//      }
//      else
//      {
//        s_iMin++;
//      }
//      s_iSec = 0;
//    }
//    else
//    {
//      s_iSec++;
//    }
//    s_iCnt500 = 0;
//  }
//  else
//  {
//    s_iCnt500++;
//  }
//}

/*********************************************************************************************************
* 函数名称：PauseClock
* 函数功能：实现时钟的启动和暂停 
* 输入参数：flag，1-暂停，0-启动
* 输出参数：void
* 返 回 值：void
* 创建日期：2018年01月01日
* 注    意：
*********************************************************************************************************/      
void  PauseClock(u8 flag)
{
  s_iClockPauseFlag = flag;  
}

/*********************************************************************************************************
* 函数名称：GetTimeVal
* 函数功能：获取当前的时间值 
* 输入参数：时间值的类型
* 输出参数：void
* 返 回 值：获取的时间值，小时、分钟或秒
* 创建日期：2018年01月01日
* 注    意：
*********************************************************************************************************/
i16   GetTimeVal(u8 type)
{
  i16 timeVal;

  switch(type)
  {
  case TIME_VAL_HOUR:
    timeVal = s_iHour;
    break;
  case TIME_VAL_MIN:
    timeVal = s_iMin;
    break;
  case TIME_VAL_SEC:
    timeVal = s_iSec;
    break;
  case TIME_VAL_YEAR:    // 新增
    timeVal = s_iYear;
    break;
  case TIME_VAL_MONTH:   // 新增
    timeVal = s_iMonth;
    break;
  case TIME_VAL_DAY:     // 新增
    timeVal = s_iDay;
    break;
  case TIME_VAL_WEEK:    // 新增
    timeVal = s_iWeek;
    break;
  default:
    break;
  } 
  
  return(timeVal);
}

/*********************************************************************************************************
* 函数名称：SetTimeVal
* 函数功能：设置当前的时间值 
* 输入参数：type-时间值的类型，timeVal-要设置的时间值
* 输出参数：void
* 返 回 值：void
* 创建日期：2018年01月01日
* 注    意：
*********************************************************************************************************/      
void  SetTimeVal(u8 type, i16 timeVal)
{
  switch(type)
  {
    case TIME_VAL_HOUR:
      s_iHour = timeVal;
      break;
    case TIME_VAL_MIN:
      s_iMin  = timeVal;
      break;
    case TIME_VAL_SEC:
      s_iSec  = timeVal;
      break;
    case TIME_VAL_YEAR:
      s_iYear = timeVal;
      break;
    case TIME_VAL_MONTH:
      if(timeVal >= 1 && timeVal <= 12)  // 月份范围检查
        s_iMonth = timeVal;
      break;
    case TIME_VAL_DAY:
      // 简单范围检查，具体天数由月份决定
      if(timeVal >= 1 && timeVal <= 31)
        s_iDay = timeVal;
      break;
    case TIME_VAL_WEEK:
      if(timeVal >= 1 && timeVal <= 7)   // 星期范围检查
        s_iWeek = timeVal;
      break;
    default:
      break;
  } 
}   

/*********************************************************************************************************
* 函数名称：DispTime
* 函数功能：显示当前的时间
* 输入参数：hour，min，sec
* 输出参数：void
* 返 回 值：void
* 创建日期：2018年01月01日
* 注    意：
*********************************************************************************************************/
//void  DispTime(i16 hour, i16 min, i16 sec)    //显示当前的时间
//{
//  printf("Now is %02d:%02d:%02d\n", hour, min, sec);
//}
void  DispTime(i16 year, i8 month, i16 day, i8 week, i16 sec)    //显示当前的时间
{
    static const char* weekStr[7] = { "Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun" };
    printf("Now is %04d-%02d-%02d %s %03d\n", year,month,day,weekStr[s_iWeek-1],sec);
}

//判断闰年
static u8 IsLeapYear(i16 year)
{
  if(0 == s_iYear % 4 && (0 != s_iYear % 100 || 0 == s_iYear % 400))
  {
    return(TRUE);
  }
  else
  {
    return(FALSE);
  }
}

//获取日期
static i8 GetMonthDays(i16 year,i8 month)
{
	static const u8 a_iMonthDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if(2 == month && IsLeapYear(year)){
      return(29);
    }
    else
    {
      return(a_iMonthDays[s_iMonth - 1]);
	}
}

//输出年月日
/*void  RunClockPer2Ms(void)
{
  static i16 s_iCnt500 = 0;

  if(499 <= s_iCnt500 && 0 == s_iClockPauseFlag)
  {
    if(59 <= s_iSec)
    {
      if(59 <= s_iMin)
      {
        if(23 <= s_iHour)
        {
          int day;
          s_iHour = 0;
          day = GetMonthDays(s_iYear, s_iMonth);
          if (s_iDay >= day)
          {
              s_iDay = 1;
              if (12 <= s_iMonth)
              {
                  s_iMonth = 1;
                  s_iYear++;

              }
              else
              {
                  s_iMonth++;
			  }
              
          }
          else
          {
            s_iDay++;
          }
        }
        s_iWeek++;
        if (s_iWeek > 7)s_iWeek = 1;
        else
        {
          s_iHour++;
        }
        s_iMin = 0;
      }
      else
      {
        s_iMin++;
      }
      s_iSec = 0;
    }
    else
    {
      s_iSec++;
    }
    s_iCnt500 = 0;
  }
  else
  {
    s_iCnt500++;
  }
}
*/

void RunClockPer2Ms(void){
    static i16 s_iCnt500 = 0;
  if (499 <= s_iCnt500 && 0 == s_iClockPauseFlag)
  {
      // 1秒到，更新一天
      s_iSec++;
      s_iDay++;         // 天数+1
      s_iWeek++;        // 星期+1（无论是否进位，每天都要更新）

      // 星期循环（1-7）
      if (s_iWeek > 7)
      {
          s_iWeek = 1;
      }

      // 检查月份进位（当月天数是否超过本月最大天数）
      if (s_iDay > GetMonthDays(s_iYear, s_iMonth))
      {
          s_iDay = 1;     // 天数重置为1（下月1号）

          // 月份进位
          if (s_iMonth == 12)  // 若当前是12月
          {
              s_iMonth = 1;      // 月份重置为1月
              s_iYear++;         // 年份+1（进入下一年）
          }
          else
          {
              s_iMonth++;        // 月份+1
          }
      }

      s_iCnt500 = 0;  // 重置2ms计数器
  }
  else
  {
      s_iCnt500++;    // 累计2ms计数
  } 
}


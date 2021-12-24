//
//  HDKeyMapper.h
//  HDKitBase
//
//  Created by air on 2021/12/21.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


/*
 使用事例
 -(MXKeyMapper *)keyMapper{
     if ([ConfigManager sharedManager].dvrType==2) {
         MXKeyMapper *mapper=[[MXKeyMapper alloc]init];
         mapper.keyMapper=@{@"eventid":@"Cmd"};//eventid json返回的字段  Cmd model中定义的字段
         return mapper;
     }
     return nil;
 }
*/

@interface HDKeyMapper : NSObject

@property (nonatomic,strong)NSDictionary *keyMapper;

@end

NS_ASSUME_NONNULL_END

//
//  HDWaitImage.h
//  HDKitBase
//
//  Created by air on 2021/12/21.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface HDWaitImage : UIImageView

@property (nonatomic,strong)UIActivityIndicatorView *hudImage;
-(void)starHud;
-(void)stopHud;

@end

NS_ASSUME_NONNULL_END

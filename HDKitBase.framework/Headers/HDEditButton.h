//
//  HDEditButton.h
//  HDKitBase
//
//  Created by air on 2021/12/21.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol HDEditButtonDelegate;

@interface HDEditButton : UIButton

@property (nonatomic,weak) id <HDEditButtonDelegate>delegate;
@property (nonatomic,strong)NSIndexPath *indexPath;
@property (nonatomic,strong)id cell;

@end


@protocol HDEditButtonDelegate <NSObject>

-(void)editButtonFinishWith:(HDEditButton *)button;

@end

NS_ASSUME_NONNULL_END

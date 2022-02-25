//
//  ViewController.m
//  KitDemo
//
//  Created by air on 2021/12/24.
//

#import "ViewController.h"

@interface ViewController ()<HDVideoPlayerDelegate>
@property (nonatomic,strong)HDPlayer *player;
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.player=[[HDPlayer alloc]initWithCreatePlayerDelegate:self menuType:VideoMenuTypeDefault];
    [self.view addSubview:self.player];
    [self.player mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.mas_equalTo(self.hdTopBar+self.hdTopStatus);
        make.height.mas_equalTo(Screen_Width/1.77777);
        make.left.mas_equalTo(self.view);
        make.right.mas_equalTo(self.view);
    }];
}

///播放视频是否准备就绪
-(void)checkVideoReadyPlayResult:(NSError * __nullable )error withFileMessage:(FFMediaInfoModel * __nullable)mediaInfo{
    
    if (error) {
        HDLog(@"播放失败：：：：%@",error.description);
    }else{
        [self.player play];
    }
}
///获取播放文件地址
-(NSString *)getVideoPlayUrl{
    NSString *url=@"http://vd2.bdstatic.com/mda-ijufs1h3n23zu1h0/sc/mda-ijufs1h3n23zu1h0.mp4";
    return url;
}

-(HDPlayerType)specifyCurrentPlayerType{
    return AVPlayerType;
}
-(BOOL)observePhoneAllowInterfaceOrientations{
    return YES;
}
-(void)changePhoneOrientationsAlloc{
    [self.player mas_remakeConstraints:^(MASConstraintMaker *make) {
        make.top.mas_equalTo(self.hdTopBar+self.hdTopStatus);
        make.height.mas_equalTo(Screen_Width/1.77777);
        make.left.mas_equalTo(self.view);
        make.right.mas_equalTo(self.view);
    }];
}
@end

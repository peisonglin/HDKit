//
//  IJKPlayerViewController.m
//  KitDemo
//
//  Created by 裴五 on 2022/7/21.
//

#import "IJKPlayerViewController.h"
#import <IJKMediaFramework/IJKMediaFramework.h>
@interface IJKPlayerViewController ()
@property(nonatomic, strong) id <IJKMediaPlayback> playerVc;
@end

@implementation IJKPlayerViewController

- (void)viewDidLoad {
    
    [super viewDidLoad];
    
//    [self.playerVc shutdown];
//    self.playerVc = nil;
//    NSString *string=@"http://192.168.1.254/DCIM/Normal/20220715_211427_0986_N_A.MP4";
//    IJKFFOptions *options = [IJKFFOptions optionsByDefault];
//    [IJKFFMoviePlayerController setLogReport:NO];
//    [IJKFFMoviePlayerController setLogLevel:k_IJK_LOG_INFO];
//    IJKFFMoviePlayerController *playerVc = [[IJKFFMoviePlayerController alloc] initWithContentURLString:string withOptions:options];
//    [playerVc prepareToPlay];
//    playerVc.scalingMode = IJKMPMovieScalingModeFill;
//    [playerVc setPauseInBackground:YES];
////    self.playerVc = playerVc;
//    playerVc.view.frame = CGRectMake(0, 100, Screen_Width, Screen_Width/1.777778);
////    [self.view insertSubview:playerVc.view atIndex:0];
//    [self.view addSubview:playerVc.view];
////    [playerVc play];
    
    
    
    NSString *string=@"http://192.168.1.254/DCIM/Normal/20220715_211427_0986_N_A.MP4";
    IJKFFOptions *options = [IJKFFOptions optionsByDefault]; //使用默认配置
    self.playerVc = [[IJKFFMoviePlayerController alloc] initWithContentURL:[NSURL URLWithString:string] withOptions:options];
    UIView *playerView = [self.playerVc view];
    playerView.frame = CGRectMake(0, 100, Screen_Width, Screen_Width/1.777778);;
    playerView.autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight;
    [self.view addSubview:playerView];
    [self.playerVc setScalingMode:IJKMPMovieScalingModeAspectFit];
    self.playerVc.shouldAutoplay = YES;
    [self.playerVc prepareToPlay];
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end

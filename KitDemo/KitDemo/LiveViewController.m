//
//  LiveViewController.m
//  KitDemo
//
//  Created by 裴五 on 2022/8/4.
//

#import "LiveViewController.h"

@interface LiveViewController ()<HDLivePlayerDelegate>
@property (nonatomic,weak)id object;
@property (nonatomic,strong)HDPlayer *player;
@property (nonatomic,strong)HDLivePlayer *livePlay;
@property (nonatomic,assign)BOOL isskkkk;
@end

@implementation LiveViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.view.backgroundColor=[UIColor blackColor];
    NSLog(@"启动完成");

    WS(weakSelf);
    self.object=[HDTool createDelayBlockAfterTime:5 withBlock:^{
        NSLog(@"延迟需要干的事情");
//        [weakSelf.livePlay stop];
    }];

    NSString *s=MXSaveFileName(@"5555");
    s=[s stringByAppendingPathComponent:@"%d.jpg"];
    NSArray *array=@[@"ffmpeg",@"-i",MXGetFilePath(@"1.ts"),@"-vf",@"fps=1",@"-s",@"111x63",s];

    s=MXSaveFileName(@"1.ts");
//    array=@[
//        @"ffmpeg",@"-i",
//        MXGetFilePath(@"1.ts"),
//        @"-b:v",
//        @"640K",
//        @"-r",
//        @"30",
//        @"-s",
//        @"1920x1080",
//        @"-vcodec",
//        @"mpeg4",
//        @"-y",
//        s];

//    array=@[
//        @"ffmpeg",@"-i",
//        MXGetFilePath(@"8888.mp4"),
//        @"-b:v",
//        @"6400K",
//        @"-r",
//        @"30",
//        @"-s",
//        @"1920x1080",
//        @"-vcodec",
//        @"h264",
//        @"-y",
//        s];

//
    [HDFFmpegOrder operationVideoFileWith:array processBlock:^(float process,int code) {
        if (code>=0) {
            NSLog(@"process::::::%f",process);
        }else{
            NSLog(@"出现错误：：：：%d",code);
        }
    } completionBlock:^(NSError * _Nonnull error) {
        NSLog(@"%@",s);
    }];

   
    double second=CFAbsoluteTimeGetCurrent();
    FFGpsTool *tool=[[FFGpsTool alloc]init];
//    NSString *url=@"http://vd2.bdstatic.com/mda-ijufs1h3n23zu1h0/sc/mda-ijufs1h3n23zu1h0.mp4";
    [tool createVideoForGPSUrl:MXGetFilePath(@"20201027113419_000002A.MP4")];
//    [tool createVideoForGPSUrl:MXGetFilePath(@"1636363112567997.mp4")];
    
//    [tool createVideoForGPSUrl:MXGetFilePath(@"视频.MP4")];
    NSLog(@"ffmpeg执行耗时::::::::::::::::::::::::::::::::::::%f",fabs(CFAbsoluteTimeGetCurrent() - second));
    
    
    
//    self.player=[[HDPlayer alloc]initWithFrame:CGRectMake(0, 100, 100, 100)];
//    [self.view addSubview:self.player];
//    self.player.backgroundColor=[UIColor redColor];

    
    
    self.livePlay=[[HDLivePlayer alloc]initWithFrame:CGRectMake(0, 0, Screen_Width, Screen_Width/1.77777) withPlayType:FFMPlayeType];
    self.livePlay.delegate=self;
    self.livePlay.backgroundColor=[UIColor redColor];
    self.livePlay.maxTimeOut=3;
    [self.view addSubview:self.livePlay];
    [self.livePlay mas_makeConstraints:^(MASConstraintMaker *make) {
        make.height.mas_equalTo(Screen_Width/1.77777);
        make.top.mas_equalTo(self.view).offset(self.hdTop);
        make.left.mas_equalTo(self.view);
        make.right.mas_equalTo(self.view);
    }];

    [self.livePlay star];
    
   

//    Camera.Menu.VideoQuality=Super Fine
    
//    NSString *url=@"http://192.168.1.1/cgi-bin/Config.cgi?action=get&property=Camera.Preview.*";
////    url=@"http://192.168.1.1/cgi-bin/Config.cgi?action=get&property=Camera.Menu.*";
////    url=@"http://192.168.1.1/cgi-bin/Config.cgi?action=get&property=Camera.Preview.MJPEG.status.*";
//    url=@"http://192.168.1.1/cgi-bin/Config.cgi?action=dir&property=DCIM&format=all&count=16&from=0";
//    [HDWebClient GetNewDevice:url parametes:@{} controller:self success:^(id responObject) {
//        if ([responObject isKindOfClass:[NSDictionary class]]) {
//
//        }else{
//
//        }
//        NSLog(@"%@",responObject);
//    } failure:^(NSError *error) {
//        NSLog(@"3333");
//    }];

    UIButton *button2=[[UIButton alloc]initWithFrame:CGRectMake(150, Screen_Height/2+100+60, 50, 50)];
    button2.backgroundColor=[UIColor yellowColor];
    [button2 setTitle:@"返回" forState:0];
    [button2 setTitleColor:[UIColor blackColor] forState:0];
    [button2 addTarget:self action:@selector(buttonAction2:) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:button2];
    
    // Do any additional setup after loading the view.
}


-(void)buttonAction2:(UIButton *)button{
    button.userInteractionEnabled=NO;
    [[HDPingObject sharedManager] startPingCallbackHandler:^(BOOL success) {
        if (success) {
            NSLog(@"ping完成一轮成功");
        }else{
            NSLog(@"ping完成一轮失败");
        }
        button.userInteractionEnabled=YES;
    }];
    
}
-(BOOL)videoWillChangeRecState{
    return self.isskkkk;
}

///获取播放地址
-(NSString *_Nullable)livePlayURLString{
//    return @"http://192.168.1.254:8192";
//    return @"rtsp://192.168.1.1/liveRTSP/av4";
    return @"rtsp://192.168.1.254/xxx.mov";
//    return @"http://192.168.1.254:8192";
}
///播放错误
-(void)didInterruptCallError:(NSError * __nullable)error{
    NSLog(@"直播错误：：：：%@",error.userInfo[@"message"]);
}
///当前是否允许旋转横竖屏
-(BOOL)observePhoneAllowInterfaceOrientations{
    return NO;
}
///旋转横竖屏通知
-(void)changePhoneInterfaceOrientations:(UIDeviceOrientation)orientation{
    NSLog(@"旋转");
    
    if (orientation==UIDeviceOrientationLandscapeLeft || orientation==UIDeviceOrientationLandscapeRight) {
        self.navigationController.navigationBarHidden=YES;
        [self.livePlay mas_remakeConstraints:^(MASConstraintMaker *make) {
            CGFloat width=Screen_Height*1.77778;
            CGFloat offset=(Screen_Width-width)/2;
            make.top.mas_equalTo(self.view);
            make.bottom.equalTo(self.view);
            make.left.mas_equalTo(self.view).offset(offset);
            make.right.mas_equalTo(self.view).offset(-offset);
            make.center.mas_equalTo(self.view);
        }];
    }else{
        self.navigationController.navigationBarHidden=NO;
        [self.livePlay mas_remakeConstraints:^(MASConstraintMaker *make) {
            make.height.mas_equalTo(Screen_Width/1.77777);
            make.top.mas_equalTo(self.view).offset(self.hdTop);
            make.left.mas_equalTo(self.view);
            make.right.mas_equalTo(self.view);
        }];
    }
    
}
- (BOOL)prefersStatusBarHidden{

//  [self performSelector:@selector(setNeedsStatusBarAppearanceUpdate)];
    UIInterfaceOrientation orientation = [UIApplication sharedApplication].statusBarOrientation;
    if (orientation == UIInterfaceOrientationPortrait) {
        return NO;
    }else {
        return YES;
    }

}

-(void)rotateViewAnimated:(UIView*)view withDuration:(CFTimeInterval)duration byAngle:(CGFloat)angle{
    
    [CATransaction begin];
    CABasicAnimation *rotationAnimation;
    rotationAnimation = [CABasicAnimation animationWithKeyPath:@"transform.rotation.z"];
    rotationAnimation.byValue = [NSNumber numberWithFloat:angle];
    rotationAnimation.duration = duration;
    rotationAnimation.removedOnCompletion = YES;
    
    [CATransaction setCompletionBlock:^{
        //view.transform = CGAffineTransformRotate(view.transform, angle);
    }];
    
    [view.layer addAnimation:rotationAnimation forKey:@"rotationAnimation"];
    [CATransaction commit];
}



-(BOOL)shouldAutorotate{
    return YES;
}
//支持的方向
-(UIInterfaceOrientationMask)supportedInterfaceOrientations {
    return UIInterfaceOrientationMaskPortrait;
}
-(UIInterfaceOrientation)preferredInterfaceOrientationForPresentation{
    return UIInterfaceOrientationPortrait;
}



-(void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event{
////    [self.livePlay star];
//    [MXTool cancelDelayedBlock:self.object];
//    llolololViewController *p=[[llolololViewController alloc]init];
//    p.modalPresentationStyle = 0;
//    [self presentViewController:p animated:YES completion:nil];

//    [self.navigationController pushViewController:p animated:YES];
//
//
////    [self rotateViewAnimated1:self.livePlay withDuration:3 byAngle:30];
////    [self fffffff];
    
    
    
    
}

-(void)liveWillStarReconnection:(void (^)(BOOL))connectBloc{
    connectBloc(YES);
}
- (void)rotateViewAnimated1:(UIView*)view withDuration:(CFTimeInterval)duration byAngle:(CGFloat)angle{
    [CATransaction begin];

    CABasicAnimation *rotationAnimation;
    rotationAnimation = [CABasicAnimation animationWithKeyPath:@"transform.rotation.y"];
//    rotationAnimation.byValue = [NSNumber numberWithFloat:angle];
    rotationAnimation.fromValue = [NSNumber numberWithFloat:0];
    rotationAnimation.toValue = [NSNumber numberWithFloat:angle];
    rotationAnimation.duration = 1;
    rotationAnimation.removedOnCompletion = NO;

//    [CATransaction setCompletionBlock:^{
////        view.transform = CGAffineTransformRotate(view.transform, angle);
//    }];

    [view.layer addAnimation:rotationAnimation forKey:@"rotationAnimation"];

    [CATransaction commit];
    
    
   
    
}

- (void) animationFinished: (id) sender{

NSLog(@"animationFinished !");

}


- (void)spinOut:(id)sender
{
   NSTimeInterval animationTime=0.85;

    [UIView animateWithDuration:animationTime delay:0 options: UIViewAnimationOptionCurveLinear animations:^{
        // setup the animation to spin the current view out
        [CATransaction begin];
        [CATransaction setDisableActions:YES];
        CABasicAnimation *spinOut = [CABasicAnimation animationWithKeyPath:@"transform.rotation.y"];
        [spinOut setDelegate:self];
        [spinOut setDuration:animationTime];
        CAMediaTimingFunction *tf = [CAMediaTimingFunction functionWithName:kCAMediaTimingFunctionEaseIn];
        [spinOut setTimingFunction:tf];
        [spinOut setFromValue:[NSNumber numberWithFloat:M_PI * 0.0]];
        [spinOut setToValue:[NSNumber numberWithFloat:M_PI * 0.5]];
        [spinOut setRemovedOnCompletion:NO];
        [spinOut setFillMode:kCAFillModeForwards];
        ;
        // setup variables used to roll in the next view on animation completion.
        [self.livePlay.layer addAnimation:spinOut forKey:@"111122555225"];
        
        [CATransaction commit];
    }completion:^(BOOL finished){
//        [self setFlipOutAnimationTimer:[NSTimer scheduledTimerWithTimeInterval:animationTime target:self selector:@selector(spinIn:) userInfo:nil repeats:NO]];
    }];

}
-(void)fffffff{
    //获取当前画图的设备上下文

    CGContextRef context = UIGraphicsGetCurrentContext();

    //开始准备动画

    [UIView beginAnimations:nil context:context];

    //设置动画曲线，翻译不准，见苹果官方文档

    [UIView setAnimationCurve:UIViewAnimationCurveEaseInOut];

    //设置动画持续时间

    [UIView setAnimationDuration:0.5];

    //因为没给viewController类添加成员变量，所以用下面方法得到viewDidLoad添加的子视图

    UIView *parentView = self.livePlay;

    //设置动画效果

//    [UIView setAnimationTransition: UIViewAnimationTransitionCurlDown forView:parentView cache:YES];  //从上向下

    // [UIView setAnimationTransition: UIViewAnimationTransitionCurlUp forView:parentView cache:YES];   //从下向上

    // [UIView setAnimationTransition: UIViewAnimationTransitionFlipFromLeft forView:parentView cache:YES];  //从左向右

     [UIView setAnimationTransition: UIViewAnimationTransitionFlipFromRight forView:parentView cache:YES];//从右向左

    //设置动画委托

    [UIView setAnimationDelegate:self];

    //当动画执行结束，执行animationFinished方法

    [UIView setAnimationDidStopSelector:@selector(animationFinished:)];

    //提交动画

    [UIView commitAnimations];
    
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

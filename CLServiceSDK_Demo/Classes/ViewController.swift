//
//  ViewController.swift
//  CLServiceSDK_Demo
//
//  Created by Spike on 2020/5/29.
//  Copyright © 2020 Spike. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        CLService.resgister(withAppId: "sdkdaqin", appKey: "123456", appScheme: "CLServiceSDK_demo")
    }

    @IBAction func useCLSdk() {
        CLService.start(withUserId: "JU200526175310251758", userPhone: "18848371206")
    }
    
    @IBAction func useCLDeviceService() {
        CLReaderManagerController.show()
    }
    
}


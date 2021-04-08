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
        // 这个appScheme为集成支付宝SDK时在URL-Types设置的URL Schemes，如果填写的不一致，将导致支付完成后无法返回接入方的app
        CLService.resgister(withAppId: "sdkmifengtest", appKey: "test202104061212", appScheme: "CLServiceSDK_demo")
    }

    @IBAction func useCLSdk() {
        CLService.setDebugMode(true)
        CLService.start(withUserId: "1002", userPhone: "19900001002")
    }
    
    @IBAction func useCLDeviceService() {
        CLReaderManagerController.show()
    }
    
}


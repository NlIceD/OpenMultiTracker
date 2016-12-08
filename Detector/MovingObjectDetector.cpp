////
//// Created by Ars Poyezzhayev on 06.12.16.
////
//
//#include "MovingObjectDetector.h"
//
//MovingObjectDetector::MovingObjectDetector(cv::Mat& gray)
//{
//    m_fg = gray.clone();
//    m_bs = std::make_unique<BackgroundSubtract>(gray.channels());
//    m_bs->init(gray);
//
//    m_minObjectSize.width = std::max(5, gray.cols / 100);
//    m_minObjectSize.height = m_minObjectSize.width;
//}
//
//MovingObjectDetector::~MovingObjectDetector(void)
//{
//}
//
//void MovingObjectDetector::setMinObjectSize(cv::Size minObjectSize)
//{
//    m_minObjectSize = minObjectSize;
//}
//
////----------------------------------------------------------------------
//// Detector
////----------------------------------------------------------------------
//void MovingObjectDetector::detectContour()
//{
//    m_rects.clear();
//    m_centers.clear();
//    std::vector<std::vector<cv::Point> > contours;
//    std::vector<cv::Vec4i> hierarchy;
//    cv::Mat edges;
//    cv::Canny(m_fg, edges, 50, 190, 3);
//    cv::findContours(edges, contours, hierarchy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE, cv::Point());
//    if (contours.size() > 0)
//    {
//        for (size_t i = 0; i < contours.size(); i++)
//        {
//            cv::Rect r = cv::boundingRect(contours[i]);
//
//            if (r.width >= m_minObjectSize.width &&
//                r.height >= m_minObjectSize.height)
//            {
//                m_rects.push_back(r);
//                m_centers.push_back((r.br() + r.tl())*0.5);
//            }
//        }
//    }
//}
//
//const std::vector<Point_t>& MovingObjectDetector::detect(cv::Mat &gray)
//{
//    m_bs->subtract(gray, m_fg);
//
//    detectContour();
//    return m_centers;
//}
//
//const std::vector<cv::Rect>& MovingObjectDetector::getDetects() const
//{
//    return m_rects;
//}
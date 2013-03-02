package com.controller;

import java.util.ArrayList;
import java.util.List;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.validation.Valid;

import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.validation.BindingResult;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.servlet.ModelAndView;

import com.domain.FeedDomain;
import com.service.FeedService;

@Controller
@RequestMapping(value = "/feed.html")
public class FeedController extends BaseController {

	@RequestMapping(method = RequestMethod.GET)
	public ModelAndView showForm(HttpServletRequest request,
			HttpServletResponse response) throws Exception {

		System.out.println("Session is "
				+ request.getSession().getAttribute("admin"));
		if (request.getSession().getAttribute("admin") == null
				|| !request.getSession().getAttribute("admin")
						.equals(this.password)) {
			System.out.println("NE");
			return new ModelAndView("redirect:login.html");
		}
		ModelAndView modelAndView = new ModelAndView("feed");
		modelAndView.addObject("feedDomain", new FeedDomain());
		try {
			FeedService feedService = new FeedService();
			List<FeedDomain> feedDomainList = feedService.getAllFeeds();
			modelAndView.addObject("feeds", feedDomainList);
		} catch (Exception exception) {
			exception.printStackTrace();
			throw exception;
		}
		return modelAndView;
	}

	@RequestMapping(method = RequestMethod.POST)
	public ModelAndView addFeed(@Valid FeedDomain feedDomain,
			BindingResult result, HttpServletRequest request,
			HttpServletResponse response, Model modelMap) throws Exception {

		System.out.println("1 step size   "
				+ feedDomain.getCategoryDomainList().size());
		System.out.println("FeedId   " + feedDomain.getFeedId());

		try {
			// form success
			ModelAndView modelAndView = new ModelAndView("feed");
			modelAndView.addObject("feedDomain", new FeedDomain());
			FeedService feedService = new FeedService();
			feedDomain = feedService.getFeedsById(feedDomain.getFeedId());
			System.out.println("2 step size   "
					+ feedDomain.getCategoryDomainList().size());
			List<FeedDomain> feedDomainList = new ArrayList<FeedDomain>();
			feedDomainList.add(feedDomain);
			feedService.sendFeedsToEmails(feedDomainList);
			feedDomainList = feedService.getAllFeeds();
			modelAndView.addObject("feeds", feedDomainList);
			return modelAndView;

		} catch (Exception exception) {
			exception.printStackTrace();
			feedDomain.setFeed("");
			feedDomain.setUserName("");
			feedDomain.setCategory(null);
			throw exception;
		}
	}

}

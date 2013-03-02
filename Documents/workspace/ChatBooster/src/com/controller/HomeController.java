package com.controller;

import java.util.ArrayList;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.validation.Valid;

import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.validation.BindingResult;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.servlet.ModelAndView;

import com.domain.CategoryDomain;
import com.domain.FeedDomain;
import com.service.CategoryService;
import com.service.FeedService;

@Controller
@RequestMapping(value = "/home.html")
public class HomeController extends BaseController {

	@RequestMapping(method = RequestMethod.GET)
	public String showForm(Model modelMap, HttpServletRequest request,
			HttpServletResponse response) {
		clearSession(request, response);
		modelMap.addAttribute("feedDomain", new FeedDomain());
		return "home";
	}

	@RequestMapping(method = RequestMethod.POST)
	public ModelAndView addFeed(@Valid FeedDomain feedDomain,
			BindingResult result, HttpServletRequest request,
			HttpServletResponse response, Model modelMap) throws Exception {

		try {
			if (result.hasErrors()) {
				// if validator failed
				System.out.println("Error");
				feedDomain.setFeed("");
				feedDomain.setUserName("");
				feedDomain.setCategory(null);
				return new ModelAndView("home");
			} else {
				// form success
				List<CategoryDomain> categoryDomainList = new ArrayList<CategoryDomain>();
				for (int i = 0; i < feedDomain.getCategory().length; i++) {
					CategoryDomain categoryDomain = new CategoryDomain();
					categoryDomain.setCategoryId(feedDomain.getCategory()[i]);
					categoryDomainList.add(categoryDomain);
				}
				feedDomain.setCategoryDomainList(categoryDomainList);
				FeedService feedService = new FeedService();
				List<FeedDomain> feedDomainList = new ArrayList<FeedDomain>();
				feedDomainList.add(feedDomain);
				feedService.addFeeds(feedDomainList);
				modelMap.addAttribute("feedDomain", new FeedDomain());
				ModelAndView modelAndView = new ModelAndView("home", "var",
						"Your feed has been submitted to us");
				return modelAndView;
			}
		} catch (Exception exception) {
			exception.printStackTrace();
			feedDomain.setFeed("");
			feedDomain.setUserName("");
			feedDomain.setCategory(null);
			throw exception;
		}
	}

	@ModelAttribute("categoryMap")
	public Map<Long, String> populateCategoryList() throws Exception {

		try {
			CategoryService categoryService = new CategoryService();
			List<CategoryDomain> categoryDomainList = categoryService
					.getAllCategories();

			// Data referencing for web framework checkboxes
			Map<Long, String> categoryMap = new LinkedHashMap<Long, String>();
			for (CategoryDomain categoryDomain : categoryDomainList) {
				categoryMap.put(categoryDomain.getCategoryId(),
						categoryDomain.getCategory() + "   ");
			}
			return categoryMap;
		} catch (Exception exception) {
			exception.printStackTrace();
			throw exception;
		}
	}
}

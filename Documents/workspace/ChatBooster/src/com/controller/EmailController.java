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
import com.domain.EmailDomain;
import com.service.CategoryService;
import com.service.EmailService;

@Controller
@RequestMapping(value = "/email.html")
public class EmailController extends BaseController {

	@RequestMapping(method = RequestMethod.GET)
	public String showForm(Model model, HttpServletRequest request,
			HttpServletResponse response) {
		clearSession(request, response);
		EmailDomain emailDomain = new EmailDomain();
		model.addAttribute("emailDomain", emailDomain);
		return "email";
	}

	@RequestMapping(method = RequestMethod.POST)
	public ModelAndView addEmail(@Valid EmailDomain emailDomain,
			BindingResult result, HttpServletRequest request,
			HttpServletResponse response) throws Exception {

		try {
			if (result.hasErrors()) {
				// if validator failed
				return new ModelAndView("email");
			} else {
				// form success
				List<CategoryDomain> categoryDomainList = new ArrayList<CategoryDomain>();
				for (int i = 0; i < emailDomain.getCategory().length; i++) {
					CategoryDomain categoryDomain = new CategoryDomain();
					categoryDomain.setCategoryId(emailDomain.getCategory()[i]);
					categoryDomainList.add(categoryDomain);
				}

				List<String> emailList = new ArrayList<String>();
				StringBuffer emailIdB = new StringBuffer();
				for (int i = 0; i < emailDomain.getEmailText().length(); i++) {
					if (emailDomain.getEmailText().charAt(i) == ';'
							|| emailDomain.getEmailText().length() == i + 1) {
						String emailId = emailIdB.toString();
						emailList.add(emailId);
					} else {
						emailIdB.append(emailDomain.getEmailText().charAt(i));
					}
				}
				EmailService emailService = new EmailService();
				List<EmailDomain> emailDomainList = new ArrayList<EmailDomain>();
				for (String emailId : emailList) {
					EmailDomain emailDomain2 = new EmailDomain();
					emailDomain2.setEmailId(emailId);
					emailDomain2.setCategoryDomainList(categoryDomainList);
					emailDomainList.add(emailDomain2);
				}
				emailService.addEmails(emailDomainList);
				ModelAndView modelAndView = new ModelAndView("email", "var",
						"Your emails list has been submitted to us");
				return modelAndView;
			}
		} catch (Exception exception) {
			exception.printStackTrace();
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

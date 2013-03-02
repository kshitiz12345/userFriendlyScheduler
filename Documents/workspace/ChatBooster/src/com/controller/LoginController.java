package com.controller;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.validation.Valid;

import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.validation.BindingResult;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RequestParam;

import com.domain.LoginDomain;

@Controller
@RequestMapping(value = "/login.html")
public class LoginController extends BaseController {

	@RequestMapping(method = RequestMethod.GET)
	public String showForm(Model model) {
		LoginDomain loginDomain = new LoginDomain();
		model.addAttribute("loginDomain", loginDomain);
		return "login";
	}

	@RequestMapping(method = RequestMethod.POST)
	public String addFeed(@RequestParam("password") String password,
			@Valid LoginDomain loginDomain, BindingResult result,
			HttpServletRequest request, HttpServletResponse response,
			Model modelMap) throws Exception {
		try {
			if (result.hasErrors()) {
				// if validator failed
				return new String("login");

			} else {
				// form success
				if (password.equals(this.password)) {
					request.getSession().setAttribute("admin", password);
					return "redirect:feed.html";
				} else
					return "login";

			}
		} catch (Exception exception) {
			exception.printStackTrace();
			throw exception;
		}
	}
}
